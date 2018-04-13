#include "stdafx.h"
#include "CppUnitTest.h"
#define __UNIT_TESTING__
#include "CStack.cpp"
#include "CAddStack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
// See: https://msdn.microsoft.com/en-us/library/hh419385.aspx

using namespace StackPro;

namespace UnitTest
{		
	TEST_CLASS(CStackTest)
	{
	public:
		
		TEST_METHOD(CStack_PushSingle)
		{
#define EXPECTED ((unsigned int)(45))
			// TODO: Your test code here
			CStack testObject;
			unsigned int actualValue = testObject.Push(EXPECTED);

			Assert::AreEqual( 
				EXPECTED, 
				actualValue, 
				L"Value mismatch.", 
				LINE_INFO() );
		}

		TEST_METHOD(CStack_PopEmpty)
		{
			// TODO: Your test code here
			CStack testObject;
			unsigned int actualValue = testObject.Pop();

			Assert::AreEqual(
				STACK_ERR_EMPTY,
				actualValue,
				L"Value mismatch.",
				LINE_INFO());
		}

		TEST_METHOD(CStack_PushMoreMax)
		{
#define EXPECTED ((unsigned int)(45))
			// TODO: Your test code here
			CStack testObject;
			unsigned int actualValue = -1;

			for (unsigned int i=0; i <= STACK_INFO_MAX; i++)
			{
				actualValue = testObject.Push(i);
				Assert::AreNotEqual(
					EXPECTED,
					i,
					L"Value mismatch.",
					LINE_INFO());
			}

			actualValue = testObject.Push(EXPECTED);
			Assert::AreNotEqual(
				EXPECTED,
				actualValue,
				L"Value mismatch.",
				LINE_INFO());
		}


		TEST_METHOD(CStack_MultipleObject)
		{
			// TODO: Your test code here
			CAddStack a, b(a), c(b);

			Assert::AreNotEqual(
				(unsigned int)(4),
				(unsigned int)a.getA(),
				L"Value mismatch.",
				LINE_INFO());
		}

	};



	TEST_CLASS(CAddStackTest)
	{
		TEST_METHOD(CAddStack_PushSingle)
		{
#define EXPECTED ((unsigned int)(45))
			// TODO: Your test code here
			CAddStack testObject;
			unsigned int actualValue;

			testObject.Push(EXPECTED);
			actualValue = testObject.GetSum();
			Assert::AreEqual(
				EXPECTED,
				actualValue,
				L"Value mismatch.",
				LINE_INFO());
		}

		TEST_METHOD(CAddStack_PopMultipleValid)
		{
#define EXPECTED ((unsigned int)(45))
			// TODO: Your test code here
			CAddStack testObject;
			unsigned int actualValue;

			testObject.Push(EXPECTED);
			testObject.Push(EXPECTED);
			testObject.Push(EXPECTED);

			actualValue = testObject.GetSum();
			Assert::AreEqual(
				EXPECTED*3,
				actualValue,
				L"Value mismatch.",
				LINE_INFO());
		}
	};
}