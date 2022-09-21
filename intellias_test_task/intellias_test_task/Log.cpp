#include "Log.h"
#include <iterator>
#include <iostream>
#include <fstream>

extern map<string, string> months;
extern map <string, string> months_back;

Log::Log()
{}

Log::Log(int year, int month, vector<Record> workers)
{
	this->year = year;
	vector<Record> thisMonth;
	for (auto work : workers)
	{
		if (to_string(year) + "-" + to_string(month) == work.getDate())
		{
			thisMonth.push_back(work);
		}
	}
	Workers[to_string(month)] = thisMonth;
}

void Log::outputByMonth(string month)
{
	string month_edit = months_back[month];
	vector<Record> vec = Workers[month_edit];
	cout << "Results for " << month << " " << this->year << ":" << endl;
	for (auto record : vec)
	{
		cout << record.getName() << " has worked " << record.getTotalHours() << " hours\n";
	}
}

void Log::outputByMonth(int month)
{
	vector<Record> vec = Workers[to_string(month)];
	string temp = "-" + to_string(month);
	cout << "Results for " << months[temp] << " " << this->year << ":" << endl;
	for (auto record : vec)
	{
		cout << record.getName() << " worked " << record.getTotalHours() << " hours\n";
	}
}

void Log::saveInFile()
{
	ofstream file(to_string(year) + ".txt");
	for (auto mon : Workers)
	{
		file << "In " + months["-"+ mon.first] + ":\n";
		for (auto worker : mon.second)
		{
			file << worker.getName() + " worked " + worker.getTotalHours() + " hours\n";
		}
		file << "\n";
	}
	file.close();
}

void Log::saveInFile(string name)
{
	ofstream file(name);
	for (auto mon : Workers)
	{
		file << "In " + months["-" + mon.first] + ":\n";
		for (auto worker : mon.second)
		{
			file << worker.getName() + " worked " + worker.getTotalHours() + " hours\n";
		}
		file << "\n";
	}
	file.close();
}

void Log::addWorker(Record worker)
{
	this->Workers[worker.getDate().substr(5, 2)].push_back(worker);
}

void Log::addWorkerVector(vector<Record> worker_vec)
{
	if (this->year != 0)
	{
		vector<Record> temp;
		for (auto rec : worker_vec)
		{
			if (rec.getDate().substr(0, 4) == to_string(this->year))
			{
				temp.push_back(rec);
			}
		}
		for (auto rec : temp)
		{
			Workers[rec.getDate().substr(5, 2)].push_back(rec);
		}

	}
	else if (this->year == 0)
	{
		this->year = stoi(worker_vec[0].getDate().substr(0, 4));
		vector<Record> temp;
		for (auto rec : worker_vec)
		{
			if (rec.getDate().substr(0, 4) == to_string(this->year))
			{
				temp.push_back(rec);
			}
		}
		for (auto rec : temp)
		{
			Workers[rec.getDate().substr(5, 2)].push_back(rec);
		}
	}
	return;
}