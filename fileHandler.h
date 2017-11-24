#pragma once

#include "stringHandler.h"

#include <string>
#include <fstream>
#include <iostream>
#include <ios>
#include <vector>
#include <sstream>
#include <iterator>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stringstream;

class FileHandler
{
public:
	FileHandler(const string&);
	~FileHandler();

	const string& getAsString() const;
	bool isExist() const;
	char get();

	vector<vector<string>> getCmdLists();
	vector<string> getCmdArgList(const string&);

private:

	stringstream m_ss;
	string m_file;
	string m_path;
	bool m_file_exist;

	const string error1 = "FileHandler ERROR1";
};
