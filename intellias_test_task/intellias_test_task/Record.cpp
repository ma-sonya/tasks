#include <iostream>
#include "Record.h"
#include <map>
#include <string.h>

using namespace std;

map <string, string> months = { {"-01", "January"}, {"-02"," February"},{"-03","March"},{"-04","April"},
    {"-05", "May"}, {"-06", "June"}, {"-07","July"}, {"-08","August"}, {"-09","September"}, {"-10","October"}, {"-11", "November"}, {"-12", "December"} };


Record::Record()
{}

Record::Record(
    string Name, string Email, string Department, string Position,
    string Project, string Task, string Date, int Hour
) : Name(Name), Email(Email), Department(Department), Position(Position),
Project(Project), Task(Task)
{
    this->Date = Date.substr(0,8);
    TotalHours += Hour;
    ind--;
}

Record::Record(const Record& record) : Name(record.Name), Email(record.Email), Department(record.Department), Position(record.Position),
Project(record.Project), Task(record.Task), Date(record.Date), TotalHours(record.TotalHours)
{}

string Record::res()
{
    string hours, date;
    if (ind != 0)
    {
        hours = "Total hours";
        date = "Month";
        ind = 0;
    }
    else
    {
        string d = Date.substr(4, 3);
        date = months[d] + " " + Date.substr(0, 4);
        hours = to_string(TotalHours);
    }
    
    return Name + ";" + date + ";" + hours + ";\n";;
}


void Record::addHours(int Hours)
{
    TotalHours += Hours;
}

bool Record::operator==(const Record& res) const
{
    if (res.Name == this->Name &&
        res.Department == this->Department &&
        res.Email == this->Email &&
        res.Position == this->Position &&
        res.Date.substr(0,7) == this->Date.substr(0,7))
    {
        return true;
    }
    return false;
}

int Record::ind = 1;
