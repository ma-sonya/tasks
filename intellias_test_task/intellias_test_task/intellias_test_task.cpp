#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <string, string> months;

class Record
{
public:
    Record()
    {}
    Record(
        string Name, string Email, string Department, string Position,
        string Project, string Task, string Date, int Hour
    ) : Name(Name), Email(Email), Department(Department), Position(Position),
        Project(Project), Task(Task), Date(Date)
    {
        TotalHours += Hour;
        ind--;
    }
    Record(const Record& record) : Name(record.Name), Email(record.Email), Department(record.Department), Position(record.Position),
        Project(record.Project), Task(record.Task), Date(record.Date), TotalHours(record.TotalHours)
    {}

    void display()
    {
        cout << Name << ";" << Date << ";" << to_string(TotalHours) << ";\n";
    }

    string res()
    {
        string hours, date, temp;
        if (ind == 0)
        {
            hours = "Total hours";
            date = "Month";
        }
        else
        {
            hours = to_string(TotalHours);
            temp = Date.substr(5, 2);
            date = months[temp] + " " + Date.substr(0, 4);
        }

        return Name + ";" + date + ";" + hours + ";\n";
    }
    void addHours(int Hours)
    {
        TotalHours += Hours;
    }

    string returnData()
    {
        return Name + Date.substr(0, 7);
    }

private:
    string Name;
    string Email;
    string Department;
    string Position;
    string Project;
    string Task;
    string Date;
    int TotalHours = 0;
    static int ind;
};

int Record::ind = 1;

int main()
{
    months["01"] = "January";
    months["02"] = " February";
    months["03"] = "March";
    months["04"] = "April";
    months["05"] = "May";
    months["06"] = "June";
    months["07"] = "July";
    months["08"] = "August";
    months["09"] = "September";
    months["10"] = "October";
    months["11"] = "November";
    months["12"] = "December";

    //map<string, Record> logg;

    ifstream InpFile("intel_file.csv");  
    //vector<Record> recordsss;
    vector<string> ress;

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
            //recordsss.push_back(oneRec);

            /*
                        if (logg.empty())
                        {
                            logg[oneRec.returnData()] = oneRec;
                        }
                        else
                        {
                            if (logg.find(oneRec.returnData()) == logg.end())
                            {
                                logg[oneRec.returnData()] = oneRec;
                            }
                            else
                            {
                                for (auto r : logg)
                                {
                                    if (r.first == oneRec.returnData())
                                    {                                       
                                        r.second.addHours(Hours);
                                    }
                                }
                                
                                //string temp = oneRec.returnData();
                                //logg[temp].addHours(Hours);
                            }
                        }
             */
                        
            /*            for (int i = 0; i < recordsss.size(); i++)
                        {
                            Record r = recordsss[i];
                            if ( r.returnData() == oneRec.returnData())
                            {
                                recordsss[i].addHours(Hours);
                                vector<Record>::iterator it;
                                it = recordsss.end();
                                recordsss.erase(it);
                            }
                        }
            */
           

            result << oneRec.res();
            line = "";
        }
         
        result.close();
        setlocale(LC_ALL, "ru");
        cout << "Вивiд збережено в файл \"Res.csv\" :)";
    }
    InpFile.close();

    return 0;
}