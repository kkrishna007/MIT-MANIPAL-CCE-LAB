#!/bin/sh

# Combine all command line arguments into a single string
strings=$(printf "%s\n" "$@")

# Sort the strings using the 'sort' command
sorted_strings=$(echo "$strings" | sort)

# Print the sorted strings
echo "$sorted_strings"

