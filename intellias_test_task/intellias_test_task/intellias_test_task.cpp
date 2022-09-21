#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Record.h"
#include "Log.h"
#include <map>

using namespace std;

map <string, string> months = { {"-01", "January"}, {"-02"," February"},{"-03","March"},{"-04","April"},
   {"-05", "May"}, {"-06", "June"}, {"-07","July"}, {"-08","August"}, {"-09","September"}, {"-10","October"}, {"-11", "November"}, {"-12", "December"} };
map <string, string> months_back = { {"January","01"},{" February" , "02"},{"March" ,  "03"}, {"April","04"}, 
    {"May" , "05"},{ "June", "06"}, {"July", "07"} ,{"August", "08"}, {"September", "09"}, {"October", "10"}, {"November", "11"}, {"December", "12"}};



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
            if (line.empty())
            {
                continue;
            }

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
                //line = records[i].getDate();
            }
            cout << "Output is saved in \"Res.csv\" :)\n";
        }
        catch (...)
        {
            cout << "ERROR: check input data\nFORMAT: Name;email;department;position;project;task;date;logged hours\n\n";
        }

        result.close();

    }
    InpFile.close();

    //testing class Log
    Log tto(2021, 10, records);
    tto.outputByMonth(10);
    tto.addWorker(Record("Koll", "rer@goggle.com", "MAIN", "Delivery", "007", "Main", "2021-01-18", 14));
    tto.outputByMonth("January");
    tto.addWorkerVector(records);
    tto.saveInFile();
    tto.saveInFile("test.txt");
    

    return 0;
}
