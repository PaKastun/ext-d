#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <Windows.h>

#include "stringHandler.h"
#include "config.h"

using std::string;
using std::cout;
using std::endl;
using std::map;

class cBaseToken
{

public:

	enum class TokenType {
		macro,
		typedef_enum,
		def_var,
		typedef_struct,
		func_decl,
		func_def,
	};

	cBaseToken(TokenType type_, const string& raw_);
	virtual ~cBaseToken();

	virtual void show(int offset_) const;

	void setName(const string& name_);

	TokenType getType() const;
	string getName() const;
	string getRaw() const;
	vector<string> get_raw_Lines(bool line_feed_) const;
	vector<wstring> get_raw_WLines(bool line_feed_) const;
	string getHash() const;

	void setStatic(bool value_);
	void setConst(bool value_);
	void setVolatile(bool value_);
	void setExtern(bool value_);

	bool isStatic() const;
	bool isConst() const;
	bool isVolatile() const;
	bool isExtern() const;

	virtual void write(const string& dir_, const string& file_name_, const string& mode_, vector<std::experimental::filesystem::path>* file_paths_);
	virtual vector<string> parse_members(bool root_, const string& patern_name_);

	static string get_offset_string(int offset_);

protected:
	typedef map<TokenType, string> TokenTypeNames;
	static TokenTypeNames tokenTypeNames;

	string m_name;
	TokenType m_type;

private:

	string m_raw;

	bool m_static;
	bool m_const;
	bool m_volatile;
	bool m_extern;

	string m_hash;
};