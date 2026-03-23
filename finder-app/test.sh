#!/bin/sh
writefile=/home/vboxuser/yes/yeet/wr_file.txt
writestr="yes"
dirpath=$(dirname "$writefile")
mkdir -p "$dirpath"
if [ ! -d "$dirpath" ]
then
    echo "File was not created."
    exit 1
fi
#prints the string, uses the file location as output
echo "$writestr" > "$writefile"
