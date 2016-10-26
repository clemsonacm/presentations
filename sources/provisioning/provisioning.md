### Provisioning At the Speed of Thought
*** An Intro to Ansible, Salt, and Puppet ***


### Speakers:

Robert Underwood - ACM Vice President


## Overview

1.	Why provisioning?
2.	What is provisioning?
3.	How can I get started?
	+	Puppet
	+	Ansible
	+	Salt



## Why provisioning?

+	How long does it take to install a machine?
+	What if you get a new machine?
+	What if you have 5, 10, 100, or more?
+	Ever forget to install updates?



## What is provisioning?

+	Manage files, users, and software
+	Discover facts about managed systems
+	Create "cloud" and "virtual" resources
+	Install automatically on new machines



## How do I get started?



## Puppet

+	Written in Ruby
+	Master/Agent architecture
+	**Out of Order** Processing
+	Configured in `puppet`
	+	Mix of Object Oriented and Declarative


### Puppet Specs - Basics

```puppet
user { 'acm':
	ensure => 'present',
	managehome => true
	shell => 'bash',
	group => 'acm',
	requires => Group['acm']
}
group { 'acm': 
	ensure => 'present'
}
```


### Puppet Specs - Collectors

```puppet
$users = ['acm', 'foo', 'bar']
group { 'acm': 
	ensure => 'present'
}
user { $users:
	ensure => 'present',
	managehome => true
	shell => 'bash',
	group => 'acm',
}
Group <||> -> User <||>
```


### Puppet Specs - Packages

```puppet
$gvim_package = osfamily ? {
	'RedHat' => "vim-X11",
	'Debian' => "vim-gtk3",
	default  => "gvim"
}
package { 'gvim':
	name => $gvim_package,
	ensure => 'latest'
}
```


### Puppet Specs - Services

```puppet
file {'/etc/ssh/sshd_config':
	ensure => file,
	owner => 'root',
	group => 'root',
	mode => '0644',
	contents => template("sshd_config.erb"),
	notify => Service['sshd']
}
service {'sshd':
	ensure => running,
	enable => true
	subscribe => File['/etc/ssh/sshd_config']
}
```


### External Facts - Common Code

```python
from subprocess import Popen, PIPE
def git_version()
	"""Get the git version"""
	try: 
		p = Popen(['git', '--version', stdout=PIPE, stderr=PIPE)
		out, _ = p.communicate()
	except OSError:
		out = u'0.0.0'
	version_str = out.split()[2].decode()
	major, minor, patch = [int(i) for i in version_str.split('.')][:3]
	return {
		"major" : major,
		"minor" : minor,
		"patch" : patch,
		"version_str" : version_str
	}
```


### External Facts

```python
#!/usr/bin/env python
from __future__ import print_function
facts = git_version()
for key in facts:
	print("%s=%s" % (key, facts[key]))
```


## Puppet Modules

`puppet module generate mymodule`
+	`mymodule`
	+	`manifests` - puppet files
	+	`files` - static files to serve
	+	`templates` - templated files to serve
	+	`lib` - custom facts and types
	+	`facts.d` - non-ruby facts
	+	`examples` - test cases for manifests
	+	`spec` - tests for plugins


## The Good

-   Better for weird systems
-   Most community modules: forge
-   Out-of-Order processing
-   Apache Licensed


## The Bad

-   Ruby
-   Out-of-Order processing
-   Documentation



## Ansible

+	Written in Python 2.7.X but moving to 3.X
+	Agentless architecture
	+	Requires only Python 2.7 and OpenSSH Server
+	**In Order** processing with dependencies
+	Configured in `yaml` and `jinja`


### Ansible Play Books - Basics

```yaml
---
-   hosts: all
	tasks:
	- name: create acm group
	  group: name=acm state=present
	- name: create users
	  user: name="{{item}}" state=present
	  with_items:
		- "acm"
		- "foo"
		- "bar"
```


### Ansible Play Books - Packages

```yaml
- hosts: all
  tasks:
	- name: install vim Debian
	  package: name=vim-gtk3
	  when: ansible_os_family == 'Debian'
	- name: install vim RedHat
	  package: name=vim-X11
	  when: ansible_os_family == 'RedHat'
	- name: install vim other
	  package: name=vim-X11
	  when: ansible_os_family != 'RedHat' or ansible_os_family != 'Debian'
```


### Ansible Specs - Packages Better

```yaml
#in main.yaml
---
- hosts: all
  tasks:
	-   group_by: key=os_{{ansible_os_family}}
	-   name: install gvim
		package: name="{{gvim}}" state=latest

#in group_vars/os_RedHat
---
gvim: vim-X11

#in group_vars/os_Debian
---
gvim: vim-gtk3
```


### Ansible Play Books - Services

```yaml
# in main.yaml
- hosts: all
  tasks:
	- name: configure sshd 
	  template: 
	    src:'/etc/ssh/sshd_config'
		dest: sshd_config 
		mode: 0644 
		owner: root 
		group: root
	  notify: restart sshd
	- name: start sshd
	  service: name=sshd state=running

  handlers:
	- name: restart sshd
	  service: name=sshd state=restarted
```


### External Facts

```python
#!/usr/bin/env python
from __future__ import print_function
import json

facts = {
	"changed": False,
	"ansible_facts": git_version()
}

print(json.dumps(facts))
```


## Ansible Modules

*** Only create what you need *** 

+	`mymodule`
	+	`tasks` - ansible playbooks to run
	+	`handlers` - Ansible handlers
	+	`library` - external code to run
	+	`templates` - templated files
	+	`files` - static files
	+	`vars` - variable for this module
	+	`defaults` - vars with lower precedence
	+	`meta` - dependencies


## The Good

-   Agentless
-   Documentation
-   Simple, Concise
-   Python
-   Ansible Vault
-   GPL Licensed


## The Bad

-   Slower (but not much)
-   Regressions in 2.0
-   Very opinionated
-   Less featureful



## SaltStack

+	Written in python 2.7.X but moving to 3.X
+	Mixed architecture
	+	Requires python 2.7 and OpenSSH Server for Agentless
+	**Computed Ordering**
+	Configured in `yaml` with `jinja` or `python`


## Salt Basics

```yaml
acm:
	group.present
{% for user in ['acm', 'foo', 'bar'] %}
users:
	user.present:
		name: {{user}}
		shell: bash
		groups: acm
{% endfor %}
```


## Salt Packages

```yaml
{% if grains['os_family'] == 'RedHat' %}
vim-X11:
{% elif grains['os_family'] == 'Debian' %}
vim-gtk3:
{% endif %}
	pkg.installed
```


## Salt Packages - Better

```yaml
#in sls file
{{ pillar['gvim'] }}:
	pkg.installed
```


## Salt Packages - Better

```yaml
#in pillar/top.sls
'base':
  '*':
   - package.defaults
  'os_family:RedHat':
   - package.redhat
  'os_family:Debian':
   - package.debian

#in pillar/package/defaults.sls
gvim: gvim

#in pillar/package/redhat.sls
gvim: vim-X11

#in pillar/package/debian.sls
gvim: vim-gtk3
```


## Salt Services

```yaml
/etc/ssh/sshd_config:
	file.managed:
	  - source: salt://sshd/sshd_conf
	  - user: root
	  - group: root
	  - mode: 644
	  - template: jinja

sshd:
  service.running:
    - enabled: True
    - reload: True
    - watch:
      - file: /etc/ssh/sshd_config
```


## External Facts

```python
#!/usr/bin/env python

def main():
    """gather facts"""
	return git_version()
```


## Salt Modules

*** other than init.sls names don't matter ***

+	mymodule
	+	init.sls
	+	varient.sls 
	+	varient1.sls
	+	files


## The Good

-   Fast
-   Jinja + YAML work great
-   Master/Slave isn't painful
-   Also Agentless
-   Simple, Consise
-   Reactions and Provisioning are 1st class
-   Python
-   Apache Licensed


## The Bad

-   Documenation lacks organization
-   Python only for extensions
-   No custom jinja filters



## Further Resources

+	[puppet][puppet] 
	+	visual index -- how does the language work
	+	type reference -- what types exist
	+	facter, hiera
+	[ansible][ansible] 
+	[salt][salt]

[puppet]: https://docs.puppet.com/puppet
[ansible]: https://docs.ansible.com
[salt]: https://docs.saltstack.com/en/latest/


## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
