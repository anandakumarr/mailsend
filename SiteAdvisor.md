
# Old blurb about McAfee SiteAdvisor #
I am keeping this document for historical reasons.

Some people reported that some version of ~McAfee virus scanner detects one of my software mailsend as Gaobot virus. The root of the probelm is ~McAfee SiteAdvisor. It falsely claiming that mailsend is a virus! They are basically ruining the reputation of my site, which solely exists (more than 12 years) to serve the Internet community with free software I wrote. As yahoo uses McAfee SiteAdvisor software, my site shows up as all red flagged in search. It's a shame yahoo has become so clueless! Apparently it is nothing new, McAfee SiteAdvisor is notorious for flagging sites falsely. Google on it, you will see what I mean.
I scanned with Trend Micro PC-cillin v 15.30.1151, and McAfee's very own Viruscan Enterprise 8.0, Other people have reported they scanned with Norton Antivirus, ClamAV 0.94.1/8645, avast! v4.8 Home Edition and found mailsend is clean.

The site: http://www.siteadvisor.com/sites/muquit.com/downloads/6455549/ claims that mailsend modifies registry:
```
CHANGE  [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows
NT\CurrentVersion\Prefetcher]
CHANGE  TracesProcessed=dword:00000010
CHANGE  TracesSuccessful=dword:0000000c
This is just insane!
```
mailsend does not have any code to mess with registry.
Here is my opinion on this:
Whoever reported that mailsend is a virus, was infected with Gaobot and mailsend was corrupted. I know the program is not corrupted and it has no code to mess with registry, so I think this explanation makes sense. It is also quite possible McAfee's software is just outright buggy.
If you have a better explanation, please let me know.

If you are interested to verify, I am leaving the original file: mailsend1.15b5.exe.zip (available at the mailsend page).
MD5 sum: deb005aee615bbcae84fd9d87b8d6e8d

Check the bottom of the SiteAdvisor page and check the size nd MD5 sum to make sure you are dealing with the same file.
Please verify with your Virus scanner and send me your comment, I would appreciate it!.

It's a shame McAfee accepts this kind of claim without verifying themselves! If you use my software and if you are a user of MacAfee Virus Scanner, let MacAfee know about this problem and spread the word about the abuse and slander by MacAfee SiteAdvisor! I do not gain financially from my site but this kind of irresponsible behavior from MacAfee will certainly harm many online businesses.