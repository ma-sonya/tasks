#pragma once
#include <string>

using namespace std;

class Record
{
public:
    Record();
    Record(string Name, string Email, string Department, string Position,
           string Project, string Task, string Date, int Hour);
    Record(const Record& record);

    string res();
    void addHours(int Hours);
    bool operator==(const Record& res) const;
    string getDate();
    string getName();
    string getTotalHours();

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
