#!/bin/sh
#writefile=/home/vboxuser/yes/wr_file.txt
#writestr="yes"
writefile=$1
writestr=$2
#check if 2 arguments were passed
if ! [ $# -eq 2 ]
then
    #if an arguemnt is not passed it's an empry str
    #-z checks if the string len is 0(empty str)
    if [ -z "$writefile" ] 
    then
    echo "arg1 writefile is missing!"
    fi
    if [ -z "$writestr" ]
    then
    echo "arg2 writestr is missing!"
    fi
    exit 1
fi
#prints the string, uses the file location as output
dirpath=$(dirname "$writefile")
mkdir -p "$dirpath"
if [ ! -d "$dirpath" ]
then
    echo "File was not created."
    exit 1
fi
#prints the string, uses the file location as output
echo "$writestr" > "$writefile"
