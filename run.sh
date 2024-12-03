#!/bin/bash

unset CODE_PATH_
export CODE_PATH_=$(pwd)

if [ "$CODE_PATH" != "/Users/alon/Projects/Uniform-sample-generator" ]; then
    echo "- Re-pulling repository -----------------------------------------------"
    echo ""
    git reset --hard
    git pull
    echo ""
fi

echo "- Lunching code -------------------------------------------------------"
echo ""
root ./CodeRun.cpp -l -q -b
echo ""
echo "- Operation finished --------------------------------------------------"
