#!/bin/sh

for file in $@
do
rm -i $file
done
echo "Done!"
