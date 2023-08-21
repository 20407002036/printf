#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"

# Remove trailing whitespace using sed
sed -i 's/[[:space:]]*$//' "$filename"

# Remove leading whitespace using sed
sed -i 's/^[ \t]*//' "$filename"

# Remove Windows/DOS line endings using sed
sed -i 's/\r$//' "$filename"

# Add a new line to the end of the file
echo >> "$filename"

echo "File formatting complete: $filename"
