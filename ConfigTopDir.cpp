//
// Created by alons on 14/08/2024.
//

#include <iomanip>
#include <string>

#include "TString.h"

using namespace std;

string GetCurrentDirectory()
{
    char pwd[PATH_MAX];
    getcwd(pwd, sizeof(pwd));

    string WorkingDirectory = pwd;

    return WorkingDirectory;
}

bool findSubstring(string string1, string string2)
{
    if (string1.find(string2) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

TString ConfigTopDir(TString OutPutFolder)
{
    string CurrentDir = GetCurrentDirectory();

    if (!findSubstring(CurrentDir, "Users/alon/Projects/Uniform-sample-generator"))
    {
        cout << "Current directory is '" << CurrentDir << endl;
        cout << "OutPut folder kept unchanged." << endl;
        return OutPutFolder;
    }
    else
    {
        cout << "Current directory is '" << CurrentDir << endl;
        cout << "OutPut folder changed to '" << CurrentDir << "/OutPut/" << "'" << endl;
        return CurrentDir + "/OutPut/";
    }
}

/*
TString ConfigTopDir(TString OutPutFolder)
{
    string CurrentDir = GetCurrentDirectory();

    if (findSubstring(OutPutFolder.Data(),CurrentDir))
    // if (CurrentDir == OutPutFolder.Data())
    {
        return OutPutFolder;
    }
    else
    {
        return CurrentDir + "/OutPut/";
    }
}
*/
