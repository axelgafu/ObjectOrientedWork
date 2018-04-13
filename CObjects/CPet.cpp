// CObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace CObjects
{
#include "CPet.h"


	CPet::CPet(string Name)
	{
		this->Name = Name;
	}

	string CPet::Run(void)
	{
		return Name + ": I'm running.";
	}

	string CPet::MakeSound(void)
	{
		return Name + ": Shh, shh!.";
	}



	CDog::CDog(string Name) :CPet(Name) {}

	string CDog::MakeSound(void)
	{
		return Name + ": Woof, woof!.";
	}



	CCat::CCat(string Name) :CPet(Name) {}

	string CCat::MakeSound(void)
	{
		return Name + ": Meow, meow!.";
	}


}

#ifndef __UNIT_TESTING__
int main(void)
{
	return 0;
}
#endif