#!/bin/sh
echo "Enter Filename / Path: "
read file
if [ -d "$file" ]; then
echo "$file is a directory"
elif [ -f "$file" ]; then
echo "$file is a file"
else
echo "$file is not valid"
fi
