#!/bin/sh
echo "Enter Basic"
read basic
echo "Enter TA"
read TA
echo `bc <<< "scale = 4; $basic*1.1000 + $TA"`
 
