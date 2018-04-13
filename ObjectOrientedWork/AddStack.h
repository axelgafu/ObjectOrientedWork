#pragma once
namespace StackPro
{
#include "CStack.h"
	class CAddStack :
		public CStack
	{
	public:
		CAddStack();
		CAddStack(CAddStack &);
		static unsigned int a;
		unsigned int Push(unsigned int Data);
		unsigned int Pop(void);
		~CAddStack();

		unsigned int GetSum(void);
		unsigned int getA();

	private:
		unsigned int m_uiSum;
	};


#ifndef __CAddStack_static_defs__
#define __CAddStack_static_defs__
	// Test moving this to parent.
	unsigned int CAddStack::a = 1;
#endif // !__CAddStack_static_defs__
}

