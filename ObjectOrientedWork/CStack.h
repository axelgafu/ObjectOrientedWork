#pragma once

#define STACK_ERR_EMPTY ((unsigned int)-1)
#define STACK_INFO_MAX  (10)

class CStack
{
private:
	unsigned int m_iStackPointer;
	unsigned int m_uiBuffer[STACK_INFO_MAX+1];

public:
	//static unsigned int b;

	CStack()
	{
		m_iStackPointer = 0;
		//b = 0;
	}


	unsigned int Pop();
	unsigned int Push(unsigned int);
};

#ifndef __CStack_static_defs__
#define __CStack_static_defs__
//unsigned int CStack::b = 1;
#endif // !__CStack_static_defs__
