#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include "../8.1(rec)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(FindFourthFromEndDotIndex_Test)
		{
			char str[] = "Test.string.for.unit.testing.";
			int len = strlen(str);
			int expectedResult = 11; 

			int result = FindFourthFromEndDotIndexRecursive(str, len, len - 1, 0);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(FindFourthFromEndDotIndex_NoFourthDot_Test)
		{
			char str[] = "Test.string.for.unit.testing";
			int len = strlen(str);
			int expectedResult = 4; 

			int result = FindFourthFromEndDotIndexRecursive(str, len, len -1, 0);

			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(ReplaceDotsWithStars_NoDots_Test)
		{
			char str[] = "Teststringforunittesting";
			int len = strlen(str);
			char expectedResult[] = "Teststringforunittesting"; 

			ReplaceDotsWithStarsRecursive(str, len, 0);

			Assert::AreEqual(expectedResult, str);
		}
	};
}
