#include "stdafx.h"
#define __UNIT_TESTING__
#include "CppUnitTest.h"
#include "..\CObjects\CPet.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
// See: https://msdn.microsoft.com/en-us/library/hh419385.aspx

using namespace CObjects;

namespace UnitTest
{
	TEST_CLASS(CPetTest)
	{
		TEST_METHOD(CPet_Run)
		{
			CPet *pet = new CPet("Tom");

			Assert::AreEqual(
				"Tom: I'm running.",
				pet->Run().c_str(),
				"Tom should be running.",
				LINE_INFO()
			);

			delete pet;
		}

		TEST_METHOD(CDog_MakeSound)
		{
			CDog *pet = new CDog("Tom");

			Assert::AreEqual(
				"Tom: I'm running.",
				pet->Run().c_str(),
				"Tom should be running.",
				LINE_INFO()
			);

			Assert::AreEqual(
				"Tom: Woof, woof!.",
				pet->MakeSound().c_str(),
				"Tom should be barking.",
				LINE_INFO()
			);

			delete pet;
		}

		TEST_METHOD(CPetCastCDog_MakeSound)
		{
			CPet *pet = new CDog("Tom");

			Assert::AreEqual(
				"Tom: I'm running.",
				pet->Run().c_str(),
				"Tom should be running.",
				LINE_INFO()
			);

			Assert::AreEqual(
				"Tom: Woof, woof!.",
				static_cast<CDog*>(pet)->MakeSound().c_str(),
				"Tom should be barking.",
				LINE_INFO()
			);

			delete pet;
		}


		TEST_METHOD(CPetCastCCat_MakeSound)
		{
			CPet *pet = new CCat("Spike");

			Assert::AreEqual(
				"Spike: I'm running.",
				pet->Run().c_str(),
				"Spike should be running.",
				LINE_INFO()
			);

			Assert::AreEqual(
				"Spike: Meow, meow!.",
				static_cast<CCat*>(pet)->MakeSound().c_str(),
				"Spike should be meowing.",
				LINE_INFO()
			);

			delete pet;
		}


		TEST_METHOD(CCatCastCPet_MakeSound)
		{
			CPet *pet = new CCat("Spike");

			Assert::AreEqual(
				"Spike: I'm running.",
				pet->Run().c_str(),
				"Spike should be running.",
				LINE_INFO()
			);

			Assert::AreEqual(
				"Spike: Meow, meow!.",
				pet->MakeSound().c_str(),
				"Spike should be meowing.",
				LINE_INFO()
			);

			Assert::AreEqual(
				//"Spike: Shh, shh!.", // <-- Unexpected since MakeSound overwritten.
				"Spike: Meow, meow!.",
				static_cast<CPet*>(pet)->MakeSound().c_str(),
				"Spike should be shhing.",
				LINE_INFO()
			);

			delete pet;
		}


		TEST_METHOD(CCatDCastCPet_MakeSound)
		{
			CCat *cat = new CCat("Spike");
			CPet *pet;

			Assert::AreEqual(
				"Spike: I'm running.",
				cat->Run().c_str(),
				"Spike should be running.",
				LINE_INFO()
			);

			Assert::AreEqual(
				"Spike: Meow, meow!.",
				cat->MakeSound().c_str(),
				"Spike should be meowing.",
				LINE_INFO()
			);

			pet = dynamic_cast<CPet*>(cat);

			Assert::IsNotNull(pet, L"Cast to CPet should succeeded", LINE_INFO());

			Assert::AreEqual(
				"Spike: Shh, shh!.", 
				//"Spike: Meow, meow!.", // <-- Unexpected since MakeSound overwritten.
				pet->MakeSound().c_str(),
				"Spike should be shhing.",
				LINE_INFO()
			);

			delete cat;
		}
	};
}
