#!/bin/sh

# muquit@muquit.com Jan-21-2013  
#set -x
ME=`basename $0`
NARG=$#
if [ $NARG -ne 2 ]; then
    echo "usage: $ME <TO> <FROM>"
    echo "Please specify password with SMTP_USER_PASS env var"
    exit 1
fi
TO="$1"
YOU="$2"

if [ x"$SMTP_USER_PASS" = x ]; then
    echo "Please specify password with SMTP_USER_PASS env var"
    exit 1
fi
PASS=$SMTP_USER_PASS
echo "To: $TO"
echo "From: $YOU"

#SMTP=smtp.comcast.net
SMTP=smtp.gmail.com

BINARY="./mailsend"
echo "$OS"
if [ x"$OS" = x"Windows_NT" ]; then
    BINARY="./mailsend.exe"
fi
os=`uname`
if [ x"$os" = x"Linux" ]; then
VALGRIND_LOG=/tmp/valgrind.log
VALGRIND="valgrind -v --leak-check=no --log-file=$VALGRIND_LOG"
/bin/rm -f $VALGRIND_LOG
else
VALGRIND=""
fi

$VALGRIND $BINARY -to $TO -from $YOU \
 -starttls -port 587 -auth \
 -smtp $SMTP \
 -H "X-Priority: 1" -H "Importance: high" \
 -sub test +cc +bc \
 -user $YOU -pass $PASS \
 -log /tmp/mailsend.log \
 -M "one line attachment 1" \
 -M "one line attachment 2" \
 -attach "test.txt,text/plain,i" \
 -attach "x.gif,image/gif,i" -v