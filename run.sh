#!/bin/tcsh

unsetenv CODE_PATH
setenv CODE_PATH `pwd`

if ("$CODE_PATH" != "/Users/alon/Projects/Uniform-sample-generator") then
    echo "\033[35m- Re-pulling repository -----------------------------------------------\033[0m"
    echo ""
    git pull
    git reset --hard
    git pull
    echo ""
endif

echo "\033[35m- Launching code -------------------------------------------------------\033[0m"
echo ""
root ./CodeRun.cpp -l -q -b
echo ""
echo "\033[35m- Operation finished --------------------------------------------------\033[0m"