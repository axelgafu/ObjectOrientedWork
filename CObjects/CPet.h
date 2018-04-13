#pragma once

#include <string>

using namespace std;

class CPet
{
protected:
	string Name;
public:
	CPet(string Name);
	string Run(void);
	virtual string MakeSound(void);
};


class CDog : public CPet
{
public:
	CDog(string Name);
	string MakeSound(void);
};


class CCat : public CPet
{
public:
	CCat(string Name);
	string MakeSound(void);
};