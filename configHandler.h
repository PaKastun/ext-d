#pragma once

#include "fileHandler.h"
#include <target.h>

#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class ConfigHandler
{
public:
	ConfigHandler(const string&);
	~ConfigHandler();

	void test() const;
	void test1() const;

private:

	const string cmd_settarget = "SETTARGET";

	const string error1 = "ConfigHandler Error1";
	const string error2 = "ConfigHandler Error2";

	FileHandler* m_fileHandler;
	vector<Target*> m_targets;

	bool isExist;
};