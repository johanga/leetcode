#!/bin/bash
# Read from the file file.txt and output all valid phone numbers to stdout.
# Valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx.
grep -P '^((\(\d{3}\)\s)|(\d{3}-))\d{3}-\d{4}$' file.txt
