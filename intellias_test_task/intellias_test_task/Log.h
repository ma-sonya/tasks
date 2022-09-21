#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Record.h"

using namespace std;

class Log
{
public:
	Log();
	Log(int year, int month, vector<Record> workers);

	void saveInFile();
	void saveInFile(string name);
	void outputByMonth(int month);
	void outputByMonth(string month);
	void addWorker(Record worker);
	void addWorkerVector(vector<Record> worker_vec);  // встигаєш?

private:
	map<string, vector<Record>> Workers;
	int year=0;
};


