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

void ReplaceSubStr(string& str, const string& subStr, const string& replacement)
{
    bool PrintOut = false;

    if (PrintOut) { cout << "\nstr0 = " << str << "\n"; }

    string TempSource = str;

    size_t pos = TempSource.find(subStr);

    // Iterate till index position of substring is valid:
    while (pos != std::string::npos)
    {
        // Replace the first occurrence of substring in string from position pos onwards:
        TempSource.replace(pos, subStr.length(), replacement);

        // Get the index position of next occurrence of substring in string:
        pos = TempSource.find(subStr, pos + replacement.length());
    }

    str = TempSource;

    if (PrintOut) { cout << "str1 = " << str << "\n"; }
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

TString ConfigTopDir(const bool gen_1e_events, const bool gen_ep_events, const bool gen_en_events, const double Ebeam, TString OutPutFolder)
{
    string CurrentDir = GetCurrentDirectory();
    TString FuncOut;

    if (!findSubstring(CurrentDir, "Users/alon/Projects/Uniform-sample-generator"))
    {
        cout << "Current directory is '" << CurrentDir << endl;
        cout << "OutPut folder kept unchanged." << endl;

        string OutPutFolder0 = OutPutFolder.Data();
        string OutPutFolder1 = OutPutFolder0.substr(0, OutPutFolder0.find_last_of('/') - 1);

        if (gen_1e_events)
        {
            FuncOut = OutPutFolder1 + "_1e/";
        }
        else if (gen_ep_events)
        {
            FuncOut = OutPutFolder1 + "_ep/";
        }
        else if (gen_en_events)
        {
            FuncOut = OutPutFolder1 + "_en/";
        }

        cout << "OutPutFolder = " << OutPutFolder << endl;
        exit(0);
        return FuncOut;
    }
    else
    {
        cout << "Current directory is '" << CurrentDir << endl;
        cout << "OutPut folder changed to '" << CurrentDir << "/OutPut/" << "'" << endl;

        if (gen_1e_events)
        {
            FuncOut = CurrentDir + "/OutPut_1e/";
        }
        else if (gen_ep_events)
        {
            FuncOut = CurrentDir + "/OutPut_ep/";
        }
        else if (gen_en_events)
        {
            FuncOut = CurrentDir + "/OutPut_en/";
        }

        return FuncOut;
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
