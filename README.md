Thc-Hydra Porting to Android
-----------------------------

> Zhu-Zhi-Hao  
> 2016-2-9  
###PreBuild
- Please Install Busybox !
- ADB SHELL: `tar -xf PreBuild/Thc-Hydra.tar.xz -C /data/data/`
### [更新记录](./CHANGES.md)
### INTRODUCTION
Number one of the biggest security holes are passwords, as every password
security study shows.
This tool is a proof of concept code, to give researchers and security
consultants the possiblity to show how easy it would be to gain unauthorized
access from remote to a system.

THIS TOOL IS FOR LEGAL PURPOSES ONLY!

There are already several login hacker tools available, however none does
either support more than one protocol to attack or support parallized
connects.

It was tested to compile cleanly on Linux, Windows/Cygwin, Solaris,
FreeBSD/OpenBSD, QNX (Blackberry 10) and OSX.

Currently this tool supports the following protocols:
 Asterisk, AFP, Cisco AAA, Cisco auth, Cisco enable, CVS, Firebird, FTP,
 HTTP-FORM-GET, HTTP-FORM-POST, HTTP-GET, HTTP-HEAD, HTTP-PROXY, HTTPS-FORM-GET,
 HTTPS-FORM-POST, HTTPS-GET, HTTPS-HEAD, HTTP-Proxy, ICQ, IMAP, IRC, LDAP,
 MS-SQL, MYSQL, NCP, NNTP, Oracle Listener, Oracle SID, Oracle, PC-Anywhere,
 PCNFS, POP3, POSTGRES, RDP, Rexec, Rlogin, Rsh, SAP/R3, SIP, SMB, SMTP,
 SMTP Enum, SNMP v1+v2+v3, SOCKS5, SSH (v1 and v2), SSHKEY, Subversion,
 Teamspeak (TS2), Telnet, VMware-Auth, VNC and XMPP.

However the module engine for new services is very easy so it won't take a
long time until even more services are supported.

Your help in writing, enhancing or fixing modules is highly appreciated!! :-)


