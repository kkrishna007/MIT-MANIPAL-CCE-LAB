#!/bin/bash

echo 'Finding and replacing "ex:" with "Example:"'
echo 'Done  :)'
for file in *; do
  if [[ -f "$file" ]]; then
      sed -i -e 's/^ex:/Example:/' *.txt       
      sed -i -e 's/\. ex:/\. Example:/' *.txt  
  fi
done

