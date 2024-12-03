#!/bin/tcsh

unsetenv CODE_PATHH
setenv CODE_PATHH `pwd`

if ("$CODE_PATHH" != "/Users/alon/Projects/Uniform-sample-generator") then
    echo "- Re-pulling repository -----------------------------------------------"
    echo ""
    git reset --hard
    git pull
    echo ""
endif

echo "- Launching code -------------------------------------------------------"
echo ""
root ./CodeRun.cpp -l -q -b
echo ""
echo "- Operation finished --------------------------------------------------"