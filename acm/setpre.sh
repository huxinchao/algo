#!/bin/bash
files=$(ls *.cpp 2>/dev/null)

if [ $? -eq 0 ]; then
    echo "[+] Getting cpp files"
else
    echo "[-] Can't find cpp files"
fi


for file in ${files}
do
    echo "Process: ${file}"
    sed -i "1i\//  Filename: ${file}" ${file}
done
