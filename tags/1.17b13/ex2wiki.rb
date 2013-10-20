#!/usr/bin/env ruby

########################################################################
# Generate google code wiki from mailsend -ex output
# Mar-17-2013 
########################################################################
class GenerateMailsendExample
  ME = $0
  ME_SHORT = File.basename(ME)

  def initialize
    $stdout.sync = true
    @url = "https://mailsend.googlecode.com/svn/trunk/ex2wiki.rb"
  end

  def error(msg)
    puts "Error: #{msg}"
    exit 1
  end

  def doit
    if !File.exists?("mailsend")
      error "Program mailsend does not exist"
    end
    mhash = {}
    a = []
    last_header = nil
    block_found = false
    mailsend_found = false
    header = nil
    headers = []
    o = `mailsend -ex`
    new_lines = []
    last_h = ''

    lines = o.split("\n")
    lines.each_index do |i|
      line = lines[i]
      line.chomp!
      line.strip!
      if line =~ /^Example .*$/
        next
      end

      line1 = line
      line1.chomp! if line1
      line1.strip! if line1

      line2 = lines[i + 1]
      line2.chomp! if line2
      line2.strip! if line2
      if line2 =~ /^==.*$/
        last_h = line1
        if last_header && a
          headers << last_header
          mhash[last_header] = a
          a = []
        end
        block_found = true
        last_header = line1
        header = line1
        next
      end
      x = lines[i]
      x.chomp! if x
      x.strip! if x
      if x !~ /^==.*$/
        a << x;
      end
    end
    # handle last one
    headers << last_h
    mhash[last_h] = a

    puts <<EOD
#summary Examples of mailasend
#sidebar Toc
#labels Featured
<wiki:toc />
EOD
# print version info first
    v = `mailsend -V 2>&1`.chomp
    v = v.gsub('^\s+','')
    puts <<-EOS
=VERSION=
These examples are generated using 
{{{
  $ mailsend -V
#{v}
}}}
EOS


    headers.each do |h|
    puts "=#{h}="
      a = mhash[h]
      a.each do |line|
        next if line =~ /^==.*$/
        if line =~ /^mailsend .*$/
          puts "}}}" if mailsend_found
          mailsend_found = true
          puts "{{{"
          puts " $ #{line}"
          next
        end
        if line =~ /^-.*$/
          puts " #{line}"
        else
          if mailsend_found && line.length == 0
            puts "}}}"
            mailsend_found = false
          elsif mailsend_found && line !~ /^-.*$/
            puts "}}}"
            mailsend_found = false
          else
            puts " #{line}"
          end
        end
      end
    end
  t = Time.new
  puts <<EOD
}}}
----
This wiki is auto generated by [#{@url} #{ME_SHORT}] on #{t}.
EOD

  end
end

if __FILE__ == $0
  GenerateMailsendExample.new.doit
end

