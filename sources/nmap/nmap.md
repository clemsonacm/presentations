# Intro to nmap


### Brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
Freenode! Join #clemsonacm on chat.freenode.net!

### Speakers:

Robert Underwood - ACM Vice President



## Coming Up

-   What is nmap?
-   When should it be used?
-   What can it do?



# What is nmap?


## What is nmap?

-	nmap exploration and security tool
-	Essential diagnostic tool
-   Available for most OS



# When should I use it?


## When should I use it?

-   Determining hosts in IPv4 Network
-   When you want to examine ports on a host



# What can it do?


## What can it do?

-	Host enumeration
-	Service enumeration
-	Vulnerability enumeration


## Key Commands

-   `nmap -sn network` scan network
-   `nmap -T4 -A host` intense scan host



## Target Specifications

	192.168.1.1 # Single IPv4 host
	192.168.1.0 # IPv4 network 254 hosts
	2::dead:beaf:cafe # A host in IPv6
	2::dead:beaf:cafe/24 # A host in IPv6 (use -6 flag)
	www.foobar.com # A host by hostname


## Host Discovery

-   `-sL` list Scan
-   `-sn` ping scan
-   Various types of packets `-Pn`, `-PS`, `-PA`, `-PU`, and `-PY`


## Port Scanning

-   `-p` Scan specified ports
-   `--allports` scan every port
-   Various port scans `-sS`, `-sT`, `-sU` `-sY`


## Service Scanning

-   `-O` Use OS detection
-   `-sV` Use version checking


## Scripts

-   `-sC` use default scripts
-   `--script "<option>"`
-   look for these in `/usr/share/nmap/scripts`


## Timing and Optimizations

-   `-T[1-5]` timing levels
	-   `1` is the slowest
	-   `5` is the slowest
-   evasive options


## Output Formats

-   `-oN <file>` normal output
-   `-oG <file>` grep-able output
-   `-oX <file>` xml output



## Further Resources

- [nmap](https://nmap.org/) developers of `nmap`
- [Archwiki](https://wiki.archlinux.org/index.php/Main_Page) useful command reference



## Questions

Send feedback to acm@cs.clemson.edu

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
