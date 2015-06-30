
# VERSION #
These examples are generated using
```
  $ mailsend -V
mailsend Version: @(#) mailsend v1.17b11
Compiled with OpenSSL: OpenSSL 0.9.8x 10 May 2012
```
# Show server info #
```
 $ mailsend -v -info -port 587 -smtp smtp.gmail.com
```
```
 $ mailsend -v -info -ssl -port 465 -smtp smtp.gmail.com
```
```
 $ mailsend -v -info -smtp smtp.example.com -ct 2
```
# STARTTLS + AUTHENTICATION #
```
 $ mailsend -to user@gmail.com -from user@gmail.com
 -starttls -port 587 -auth
 -smtp smtp.gmail.com
 -sub test +cc +bc -v
 -user you -pass "your_password"
```

# SSL + AUTHENTICATION #
```
 $ mailsend -to user@gmail.com -from user@gmail.com
 -ssl -port 465 -auth
 -smtp smtp.gmail.com
 -sub test +cc +bc -v
 -user you -pass "your_password"
```
> As -auth is specified, CRAM-MD5, LOGIN, PLAIN will be tried in that order.
> Use -auth-cram-md5, -auth-plan, -auth-login for specific auth mechanism.

> Note: Password can be set by env var SMTP\_USER\_PASS instead of -pass

# Attachments #
```
 $ mailsend -f user@example.com -smtp 10.100.30.1
 -t user@example.com -sub test -attach "file.txt,text/plain"
 -attach "/usr/file.gif,image/gif" -attach "file.jpeg,image/jpg"
```
```
 $ mailsend -f user@example.com -smtp 192.168.0.2
 -t user@example.com -sub test +cc +bc
 -attach "c:\file.gif,image/gif" -M "Sending a GIF file"
```
```
 $ mailsend -f user@example.com -smtp 192.168.0.2
 -t user@example.com -sub test +cc +bc -cs "ISO-8859-1"
 -attach "file2.txt,text/plain"
```
# Inline Attachment #
```
 $ mailsend -f user@example.com -d example.com -smtp 10.100.30.1
 -t user@example.com -sub test -attach "nf.jpg,image/jpeg,i"
 -M "body line1: content disposition is inline"
 -M "body line2: this is line2 of the body"
```

---

This wiki is auto generated by [ex2wiki.rb](https://mailsend.googlecode.com/svn/trunk/ex2wiki.rb) on Sat Jun 08 11:28:37 -0400 2013.