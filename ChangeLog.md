
# 1.17b14 #
  * Multiline input with -M was completely broken.
_(Oct-20-2013)_
# 1.17b13 #
  * Changed Copyright to more flexible BSD from GNU GPL. Added -copyright flag.
_(Oct-12-2013)_
  * SMTP authentication was broken if the username and passwords are long enough to create longer than 60 characters base64 encoded string. A newline was added after 60 characters causing authentication to fail. Fixes [Issue 20](https://code.google.com/p/mailsend/issues/detail?id=20). Fixes [Issue 22](https://code.google.com/p/mailsend/issues/detail?id=22).
_(Oct-12-2013)_
  * Support DESTDIR during installation. Fixes [Issue 5](https://code.google.com/p/mailsend/issues/detail?id=5).
  * Don't show SSL info in quiet mode. Fixes [Issue 21](https://code.google.com/p/mailsend/issues/detail?id=21).
_(Oct-12-2013)_
  * New ommand line option -enc for Content-Transfer-Encoding. If your one line text message with -M is non-ascii, you should use -enc base64. Note: non-ascii input from windows cmd does not work at this time, however it works fine in linux and mac.
_(Jul-01-2013)_
# 1.17b12 #
  * Add \r\n to multiple one line messages specified by -M. Possible Fix for [Issue 12](https://code.google.com/p/mailsend/issues/detail?id=12).
  * Do not show attachments in verbose mode. The option -show\_attach will enable it. Fixes [Issue 13](https://code.google.com/p/mailsend/issues/detail?id=13).
_(Jun-16-2013)_
# 1.17b11 #
  * mailsend writes "Mail sent successfully" message on stdout in interactive mode even if -quiet flag is used. Fixes [Issue 6](https://code.google.com/p/mailsend/issues/detail?id=6).
_(May-05-2013)_
# 1.17b10 #
  * If there are some kind of socket error, print the error message. If a log file is specified with -log, the error will be written there.
_(Mar-23-2013)_
  * modified Makefile.in to support make -j. Fixes [Issue 4](https://code.google.com/p/mailsend/issues/detail?id=4).
  * fixed several warnings
_(Apr-27-2013)_
# 1.17b9 #
  * There was a bug if multiple attachments were specified. The temp file was created only once and was removed. The bug shows up in Windows.
  * The flag -l is changed to -list.
  * A new flag -log is added for logging status messages to a file. It is very alpha at the moment. User -v to see anything useful. The log messages are time stamped.
_(Mar-16-2013)_
# 1.17b8 #
  * Print more error messages.
_(Mar-06-2013)_
# 1.17b7 #
  * Print some error message with errno.
_(Mar-06-2013)_
# 1.17b6 #
  * MIME temp file was created on current working directory. Now go through some huristics to determine the path.
_(Mar-05-2013)_
# 1.17b5 #
  * getaddrinfo() was not found in ws2\_32 dll in Windows 2000. included  Wspiapi.h header in msock library as per Microsoft http://support.microsoft.com/kb/955045. Thanks to Bob R for reporting the issue. It's a Windows only change.
_(Feb-21-2013)_
# 1.17b4 #
  * Added flag -H "header" to add custom headers. For example:
  * "X-Priority: 1" -H "Importance: high". Requested by David Young.
_(Feb-12-2013)_
# 1.17b3 #
  * Individual auth flags were not working.
_(Jan-21-2013)_
# 1.17b2 #
  * IPv6 address was printed wrong.
_(Aug-26-2012)_
# 1.17b1 #
  * IPv6 support for all platforms.
_(Aug-25-2012)_
  * Multiple one line message can be added with -M, for example:
  * "message line 1 " -M message line 2"
_(Aug-26-2012)_
  * First cut of debian package.
  * After sending SMTP EOM, the status code was not checked. It is possible that the server has rejected the mail due to message too large etc. Thanks to Peter Soppe for reporting it.
_(Aug-24-2012)_
  * Do not enforce authentication just because server supports it. Do it only if the user wants it.
_(Jun-29-2012)_
  * Added flag -ct `<seconds>` for connect timeout with SMTP server. The default default timeout is 5 seconds.
  * Exit with 0 if everything went well otherwise exit with 1 in case of error.
  * created man page. Added install target to Makefile.
_(July-05-2012)_
# 1.16 #
  * Added support for SMTP over SSL with -ssl. It is different than STARTTLS in the sense that it is not part of SMTP protocol, the entire connection is encrypted from start to end. Note: No checking is performed on certificate. At this time, smtp.gmail.com does SMTP over SSL on port 465.
_(Feb-27-2012)_
  * Cleaned up examples. Examples can be seen with -ex, before at least -exa was needed.
_(Feb-27-2012)_
  * Created Makefile.nmake for MS Visual Studio 10.
_(Feb-28-2012)_
# 1.15b5 #
  * New flag '-name "Your Name"' can be used to add your name in the From header, e.g. -f jdoe@example.com -name "John Doe" will create the From header as: From: John Doe `<jdoe@example.com>`
_(Apr-24-2007)_
  * Changed >`>` to [C](C.md) and `<`< to [S](S.md) in debug output to represent Client and Server respectively.
_(Apr-25-2007)_
  * The flags '-d domain' is not mandatory anymore. If not specified "localhost" will be used as domain in HELO or EHLO.
_(Apr-25-2007)_
# 1.15b4 #
  * When using -info and -smtp, message was wrong.
  * Greetings can be multi line. Thanks to Keith B Smith.
  * Some server don't say ESMTP in the greetings, but still supports it. In that case force EHLO with -esmtp. Again Thanks to Keith B Smith.
  * The flag -ex is now -example.
_(Mar-18-2007)_
# 1.15b3 #
  * Compiled on Windows with openssl 0.9.7l.
  * If addresses are specified in a file with -l, do not ask for To. Addresses int he file not not validated howerver.=1.15b2=

  * New flag -ex show examples.
  * New flag -info to show SMTP server info.
  * Few bug fixes
_(Feb-18-2007)_
# 1.15a #
  * Added support for AUTH CRAM-MD5, AUTH PLAIN and AUTH LOGIN autentication.
_(Feb-17-2007)_
  * Added support for AUTH PLAIN
_(Feb-11-2007)_
  * The flag "-a" is changed to "-attach"
_(Feb-11-2007)_
  * The flags "-m" is gone. There is no need for it anymore,  as attachment type can be changed with i or a with the flag -a. If you want a "body" text, specify it with -a "file.txt,text/plain,i" as the first attachment.
_(Feb-11-2007)_
  * STARTTLS support. If the SMTP server supports it, enable it in mailsend with flag "-starttls".
_(Feb-11-2007)_

_(Feb-11-2007)_
# 1.14 #
  * Content-disposition can be changed to attachment or inline. Example: -a "file.gif,image/gif,i". The default is attachment.
  * "file.gif,image.gif,a" is same as a "file.gif,image/gif"
_(Feb-06-2007)_
  * Bcc was broken
_(Nov-03-2006)_
# 1.13 #
  * If no subject is specified with -sub, it'll be empty. Before the default subject was "hello!"
_(Jun-25-2006)_
  * The flag -M was broken.  Thanks to Amnon S for reporting it.
_(Jun-25-2006)_
  * For text attachments, Content-Disposition was always inline. Now it'll be attachment.  Thanks to Danny Casier.
_(May-21-2006)_
# 1.12 #
  * mailsend was not adding Date header. Some SMTP servers does not add it either. Now by default it'll add the Date header (make sure your clock is set properly). If you don't want mailsend to add Date header, use the flag +D. Thanks to Mr S J Hannan for the bug report.
_(May-20-2006)_
# 1.11 #
  * Attachment seperator character is changed to a , from :. Because in Windows drive is specified with :. Thanks to Jeppe Teglgaard Mohr for pointing it out. Example:  -a "c:\file.gif,image/gif"
_(Apr-23-2006)_
  * The flag -m is back. This option can be used to attach a text or html file as a blody (inline). Example: -m "file.html,text/html". It is the caller's responsibily to make sure file type is correct. mailsend will not verify if the file is binary or text.
_(Apr-23-2006)_
  * New flag -rrr to request read receipts. Suggested by marc hubaut.
_(May-14-2006)_
  * New flag -rt to add Reply-To header.
_(May-14-2006)_
# 1.10 #
  * If the attachment type was text/plain, `<CR>``<LF>` was not added after Content-Disposition line which caused attachment to be ignored by some mail readers. Thanks to Andr�s Ghigliazza for pointing it out.
_(Apr-02-2006)_
  * added a new flag -cs to specify the character set for text/plain attachment. The default is us-ascii. But if you need some other type e.g. "ISO-8859-1", you can use this flag. Thanks to Andr�s Ghigliazza for the suggestion.
_(Apr-02-2006)_
  * For Cc or Bcc the flags must be at least -cc and -bc
_(Apr-02-2006)_
# 1.09 #
  * new flag -w to wait for Carriage Return after sending the mail.
_(Mar-29-2006)_
# 1.08 #
  * remove mailto: from To field. Now the program can be used (if configured) as the external mailsender from web browsers when clicked on the mailto link. (Mar-26-2006);=1.07=

  * The flag -m is gone. Any kind of file can be attached with -a.
  * One line message can be attached at the top with -M along with other attachment. Thanks to Smeeta Jalan for the patch.
  * srand() was not called, so the MIME tag was always the same.
_(Mar-19-2006)_
# 1.06 #
  * The flag -y is gone. Now multiple attachments can be specified with -a.  Example: -a file.txt:plain/text -a file.gif:image/gif
  * file.jpg:image/jpeg
  * new flags +b, +c
  * when stdin is greater than BUFSIZ such that a "." is encountered in the middle of a line at just the right point there was a bug that would treat that as a "." at the beginning of the line and stop taking input. Patch sent by Mike Yang.
_(Aug-20-2005)_
  * qmail compatibily patch sent by Vinicio Montagnoli.
_(Aug-20-2005)_
# 1.05 #
  * ported to Unix.
_(Feb-24-2004)_
# 1.04 #
  * Added Content-Disposition: attachment; filename="xyz". So that the name of the attachment shows up in the mail.
_(Jul-09-2003)_

---

This wiki is auto generated by [changelog2wiki.rb](https://mailsend.googlecode.com/svn/trunk/changelog2wiki.rb) on Sun Oct 20 15:11:39 -0400 2013.