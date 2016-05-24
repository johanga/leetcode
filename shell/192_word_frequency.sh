#!/bin/bash
# Read from the file words.txt and output the word frequency list to stdout.
tr ' ' '\n' < words.txt | grep -v "^\s*$" | sort | uniq -c | sed -e 's/^\s*//' | sort -rnb | awk -F ' ' '{print $2" "$1}'
# It is one of the fastest solutions(faster than 90%) :)
