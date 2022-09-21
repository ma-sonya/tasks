#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Record.h"

using namespace std;

int main()
{
    ifstream InpFile("intel_file.csv");  
    vector<Record> records;
    vector<Record>::iterator it;

    if (!InpFile)
    {
        cout << "File isn`t open" << endl;
    }
    else
    {
        ofstream result("Res.csv");

        string line = "";
        while (getline(InpFile, line))
        {
            stringstream inputString(line);

            //temporary
            string Name;
            string Email;
            string Department;
            string Position;
            string Project;
            string Task;
            string Date;
            int Hours;
            string tempStr;

            getline(inputString, Name, ';');
            getline(inputString, Email, ';');
            getline(inputString, Department, ';');
            getline(inputString, Position, ';');
            getline(inputString, Project, ';');
            getline(inputString, Task, ';');
            getline(inputString, Date, ';');
            getline(inputString, tempStr, ';');
            Hours = atoi(tempStr.c_str());

            Record oneRec(Name, Email, Department, Position, Project, Task, Date, Hours);

            it = find(records.begin(), records.end(), oneRec);
            if (it != records.end())
            {
                Record t = *it;
                t.addHours(Hours);
                *it = t;
            }
            else
            {
                records.push_back(oneRec);
            }      
            line = "";                
        }        
        try 
        {           
            for (int i =0; i < records.size(); i++)
            {
                result << records[i].res();
            }
        }
        catch (...)
        {
            cout << "Error is here :/\n";           
        }

        result.close();
        cout << "Output is saved in \"Res.csv\" :)";
    }
    InpFile.close();

    return 0;
}
