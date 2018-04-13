// ObjectOrientedWork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

namespace StackPro
{
#include "CStack.h"

	/*
	 Use this function to get the element at the top of the stack.
	 */
	unsigned int CStack::Pop()
	{
		if (m_iStackPointer > 0)
		{
			return m_uiBuffer[m_iStackPointer--];
		}

		return STACK_ERR_EMPTY;
	}

	/*
	 Use this function to insert a data at the top of the stack.
	 return: Value at the top of the stack.
	 */
	unsigned int CStack::Push(unsigned int Data)
	{
		if (m_iStackPointer < STACK_INFO_MAX)
		{
			m_uiBuffer[++m_iStackPointer] = Data;
		}

		return m_uiBuffer[m_iStackPointer];
	}


	void one(void) {}
	void one(char a = 0) {}


	int main(void)
	{
		one(0);
		return 0;
	}

}
