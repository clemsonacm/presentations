# Thou Shall Not Pass!


### An introduction to iptables, firewalld, and pf, brought to you by Clemson ACM

We're on [Steam](http://steamcommunity.com/groups/clemsonacm) &
[freenode #clemsonacm](irc://chat.freenode.net/clemsonacm)!

### Speakers:

Robert Underwood - ACM Vice President

Foster Mclane- ACM Webmaster


## Coming Up

- What is a firewall, how do I secure it?
- How are they different?
    - `iptables`
    - `firewalld`
    - `pf`
- Look at some sample configurations



## What is a firewall, how do I secure it?

- Firewall is a set of rules that control traffic
- Try to use a default reject policy
- Only open up the required ports
   - Not using ssh? Block it
   - Not using IPv6? Block it
- Log unusual traffic



# How are they different?



## iptables

- Legacy firewall for Linux
- Very simple, very powerful
- Uses a series of chains based on traffic
- Use on Linux and where you need fine control 


## Important files

- `/etc/sysconfig/iptables` \# Permanent rules
- `/etc/services` \# List of services


## Important commands

- `iptables` 
- `service iptables {start,stop,status}` 
- `systemctl {start,stop,status} iptables` 
- `iptables-save > /etc/sysconfig/iptables` 
- `iptables-restore /etc/sysconfig/iptables`



## firewalld

- Inspired by the systemd project
- Provides a ease of use layer for `iptables`
- Puts the focus on "zones" and "services"
- Controls to what apps may change the firewall
- Use on newer Linux where clarity is important


## Important Files

- `/usr/lib/firewalld/` \# Definitions 
- `/etc/firewalld/` \# Overrides 


## Important commands

- `firewall-cmd` 
- `systemctl {start,stop,status} firewalld`



## pf

- Standard firewall for BSD
- The last rule in the list wins
- Use on BSD and on your router if possible


## Important Files

- `/etc/rc.conf` \# Enable pf here
- `/etc/pf.conf` \# Actual firewall configuration


## Important commands

- `pfctl -f /etc/pf.conf` \# Load the firewall config
   - This is the only way to change the running config!
- `pfctl -sa` \# See configuration status
- `kldload pf` \# Load the pf kernel module



# Example firewalls



## iptables


## Set Up

    iptables -F && iptables -X
    iptables -A INPUT -i lo -j ACCEPT
    ext_if=$(ip route | head -n 1 | awk '{print $5}')
    broken="224.0.0.22 127.0.0.0/8, 192.168.0.0/16, 172.16.0.0/12, \
          10.0.0.0/8, 169.254.0.0/16, 192.0.2.0/24, \
          192.0.2.0/24, 198.51.100.0/24, 203.0.113.0/24, \
          169.254.0.0/16, 0.0.0.0/8, 240.0.0.0/4, 255.255.255.255/32"


## Bad packets and default deny

    iptables -P INPUT DROP


## Block ipv6

    ip6tables -P INPUT DROP
    ip6tables -P OUTPUT DROP
    ip6tables -P FORWARD DROP


## Block misbehaving addresses and log them

    iptables -N LOGDROP
    iptables -A LOGDROP -m log --log-level info --log-prefix "IPTABLES" 
       -m limit --limit 5/m --limit-burst 10 -j LOG
    iptables -A LOGDROP -j DROP


## Block more bad packets

    iptables -A INPUT -m conntrack --ctstate INVALID -j LOGDROP
    iptables -t raw -I PREROUTING -m rpfilter -j LOGDROP
    for addr in $broken; do
       iptables -A INPUT tcp -i $ext_if -s $addr -j REJECT 
    done


## Exceptions for applications

    iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
    iptables -A INPUT -m limit --limit 5/m --limit-burst 10 -m conntrack \
		--ctstate NEW -p tcp --dport 22 -j ACCEPT
    iptables -A INPUT -m limit --limit 5/m --limit-burst 10 -m conntrack \
		--ctstate NEW -p tcp --dport http -j ACCEPT
    iptables -A INPUT -m limit --limit 5/m --limit-burst 10 -m conntrack \
		--ctstate NEW -p tcp --dport https -j ACCEPT
    iptables -A INPUT -j DROP



# firewalld


## Zone

    <?xml version="1.0" encoding="utf-8"?>
    <zone>
       <short>Public</public>
       <description>This is our external interface</description>
       <interface name="enp0s3"/>
       <service name="https"/>
       <rule family="ipv4">
          <source address="10.0.0.0/8"/>
          <log>
             <limit address="5/m"/>
          </log>
          <drop/>
       </rule>
    </zone>


## Services

    <?xml version="1.0" encoding="utf-8"?>
    <service>
       <short>FOO</short>
       <description>Foo is a program that allows bar</description>
       <port protocol="tcp" port="21"/>
       <module name="nf_conntrack_foo"/>
    </service>


## Configuration

    firewall-cmd --zone=public --add-interface=$ext_if
    for addr in $broken; do
		firewall-cmd --zone=public  --add-rich-rule="rule family='ipv4' \
			source address=\"$addr\" log limit value='5/m' drop"
    done
    firewall-cmd --permanent --zone=public --add-service=ssh
    firewall-cmd --zone=public --add-service=ssh
    firewall-cmd --zone=public --add-service=https
    firewall-cmd --runtime-to-permanent



# pf


## Set Up

    #Adapted from bsdnow tutorial
    ext_if = "em0"
    broken="224.0.0.22 127.0.0.0/8, 192.168.0.0/16, 172.16.0.0/12, \
            10.0.0.0/8, 169.254.0.0/16, 192.0.2.0/24, \
            192.0.2.0/24, 198.51.100.0/24, 203.0.113.0/24, \
           169.254.0.0/16, 0.0.0.0/8, 240.0.0.0/4, 255.255.255.255/32"
    set block-policy drop
    set skip on lo0


## Bad packets and default deny

    match in all scrub (no-df max-mss 1440)
    block in all
    pass out quick on $ext_if inet keep state
    antispoof quick for ($ext_if) inet


## Block ipv6

    block out quick inet6 all
    block in quick inet6 all


## Block more bad packets

    block in quick from { $broken urpf-failed no-route } to any
    block out quick on $ext_if from any to { $broken no-route }


## Block misbehaving addresses and log them

    #Block bad actors
    table <childrens> persist
    block in log quick proto tcp from <childrens> to any

    #Block Chinese address to ssh and web
    table <chuugoku> persist file "/etc/cn.zone"
    block in quick proto tcp from <chuugoku> to any port { 80 22 }


## Exceptions for applications

    pass in on $ext_if proto tcp from any to any port 80 flags S/SA synproxy state
    pass in on $ext_if proto tcp from 1.2.3.4 to any port { 137, 139, 445, 138 }
    pass in on $ext_if proto tcp to any port ssh flags S/SA keep state \
    (max-src-conn 5, max-src-conn-rate 5/5, overload <childrens> flush)
    pass inet proto icmp icmp-type echoreq



## Summary

- Know your network
- Please use a firewall to secure your device
- Open source firewalls are powerful and can be easy to implement


## Further Resources

- [iptables](https://wiki.archlinux.org/index.php/Iptables)
- [linux homenetworking](http://www.linuxhomenetworking.com/wiki/index.php/Quick_HOWTO_:_Ch14_:_Linux_Firewalls_Using_iptables#.VWvGz-chtcQ)
- [Firewalld](https://fedoraproject.org/wiki/FirewallD)
- [pf](https://www.freebsd.org/doc/handbook/firewalls-pf.html)
- [bsdnow pf tutorial](http://www.bsdnow.tv/tutorials/pf)



## Questions

Send us feedback at `acm@cs.clemson.edu`!

This material available under [CC By-SA 4.0](http://creativecommons.org/licenses/by-sa/4.0/)
