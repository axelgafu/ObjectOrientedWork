#include "stdafx.h"


#include "AddStack.h"
namespace StackPro
{


	CAddStack::CAddStack()
	{
		m_uiSum = 0;
		a = 0;
		a++;
	}

	CAddStack::CAddStack(CAddStack &stack)
	{
		a++;
	}

	unsigned int CAddStack::Push(unsigned int Data)
	{
		m_uiSum += Data;
		return CStack::Push(Data);
	}

	unsigned int CAddStack::Pop()
	{
		unsigned int val = CStack::Pop();
		m_uiSum -= val;

		return val;
	}

	CAddStack::~CAddStack()
	{
	}

	unsigned int CAddStack::GetSum(void)
	{
		return m_uiSum;
	}

	unsigned int CAddStack::getA(void)
	{
		return a;
	}
}

#ifndef __UNIT_TESTING__
int main(void)
{
	return 0;
}
#endif