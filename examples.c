#include "mailsend.h"
void show_examples(void)
{
  (void) fprintf(stdout, "Examples of mailsend Version: @(#) mailsend v1.17b15\n\n");
  (void) fprintf(stdout,
 "  Show server info\n"
 "  ================\n"
 "   mailsend -v -info -port 587 -smtp smtp.gmail.com\n"
 "   mailsend -v -info -ssl -port 465 -smtp smtp.gmail.com\n"
 "\n"
 "  STARTTLS + AUTHENTICATION\n"
 "  =========================\n"
 "   mailsend -to user@gmail.com -from user@gmail.com\n"
 "   -starttls -port 587 -auth\n"
 "   -smtp smtp.gmail.com\n"
 "   -sub test +cc +bc -v\n"
 "   -user you -pass \"your_password\"\n"
 "   Note: Password can be set by env var SMTP_USER_PASS instead of -pass\n"
 "\n"
 "  SSL + AUTHENTICATION\n"
 "  ====================\n"
 "   mailsend -to user@gmail.com -from user@gmail.com\n"
 "   -ssl -port 465 -auth\n"
 "   -smtp smtp.gmail.com\n"
 "   -sub test +cc +bc -v\n"
 "   -user you -pass \"your_password\"\n"
 "\n"
 "   As -auth is specified, CRAM-MD5, LOGIN, PLAIN will be tried in that order.\n"
 "   Use -auth-cram-md5, -auth-plan, -auth-login for specific auth mechanism.\n"
 "\n"
 "   Note: Password can be set by env var SMTP_USER_PASS instead of -pass\n"
 "\n"
 "  One line messages\n"
 "  =================\n"
 "  One line messages are specified with -M. Each message can have its own\n"
 "  MIME type, character set and encoding type:\n"
 "\n"
 "   mailsend -f user@example.com -smtp 10.100.30.1\n"
 "   -t user@example.com -sub \"testing oneline messages\"\n"
 "   -cs \"us-ascii\"\n"
 "   -enc-type \"7bit\"\n"
 "   -M \"This is a test\"\n"
 "\n"
 "   -cs \"iso-8859-1\"\n"
 "   -enc-type \"8bit\"\n"
 "   -M \"Das Vetter ist schön!\"\n"
 "\n"
 "   -cs \"Big5\"\n"
 "   -enc-type \"base64\"\n"
 "   -M \"中文測試\"\n"
 "\n"
 "  Attachments\n"
 "  ===========\n"
 "  Only requirement of -attach is the path of the file. All other \n"
 "  attributes can be specified before -attach with appropriate\n"
 "  flags. Note: The flags must be specified correctly for each attachment,\n"
 "  otherwise the one specified in previous attachment will be used.\n"
 "\n"
 "  By default MIME type is guessed from filename extension, default \n"
 "  encoding type base64 is used:\n"
 "   mailsend -f user@example.com -smtp 10.100.30.1\n"
 "   -t user@example.com -sub \"this is a test\"\n"
 "   -attach \"file.pdf\" -attach \"file.jpg\"\n"
 "\n"
 "  But all espects of attachments can be controlled:\n"
 "   mailsend -f user@example.com -smtp 10.100.30.1\n"
 "   -t user@example.com -sub test\n"
 "    -mime-type \"text/plain\" \n"
 "    -enc-type \"7bit\"\n"
 "    -charset \"us-ascii\"\n"
 "    -attach \"file.txt\"\n"
 "\n"
 "    -enc-type \"8bit\"\n"
 "    -charset \"iso-8859-1\"\n"
 "    -attach \"deutsch.txt\"\n"
 "\n"
 "   -mime-type \"image/gif\"\n"
 "   -enc-type \"base64\"\n"
 "   -aname \"flower.gif\"\n"
 "   -attach \"/usr/file.gif\" \n"
 "\n"
 "   -mime-type \"image/jpeg\"\n"
 "   -enc-type \"base64\" \n"
 "   -attach \"file.jpeg\"\n"
 "\n"
 "  By default, content disposition of all atachments are attachment, use\n"
 "  -disposition \"inline\" to give hint to the mail reader to display it as\n"
 "  mail body. Look at FAQ# 1 for details.\n"
 "\n"
 "  Including a body\n"
 "  ================\n"
 "  Only one file can be included as a body of the mail. If the\n"
 "  file is not us-ascii, the SMTP server has to support it. If you \n"
 "  include a binary file, result is undefined.\n"
 "\n"
 "   mailsend -f user@gmail -t user@example.com -smtp smtp.gamil.com\n"
 "    -port 587 -starttls -auth -user user@gmail.com -pass secret \n"
 "    -charset \"utf-8\"\n"
 "    -mime-type \"text/plain\"\n"
 "    -msg-body \"file.txt\"\n"
);
}
