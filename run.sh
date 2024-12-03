#!/bin/bash

unset CODE_PATHH
export CODE_PATHH=$(pwd)

if [ "$CODE_PATHH" != "/Users/alon/Projects/Uniform-sample-generator" ]; then
    echo "- Re-pulling repository -----------------------------------------------"
    echo ""
    git reset --hard
    git pull
    echo ""
fi

echo "- Launching code -------------------------------------------------------"
echo ""
root ./CodeRun.cpp -l -q -b
echo ""
echo "- Operation finished --------------------------------------------------"