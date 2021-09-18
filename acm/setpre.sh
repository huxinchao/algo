#!/bin/bash
files=$(ls *.cpp)
for file in ${files}
do
    echo "Process: ${file}"
    sed -i "1i\//  Filename: ${file}" ${file}
    

done
