#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_4/Main.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestFindCharacters)
		{
			ifstream inputFile("tst.txt");
			string startString = "s";
			string endString = "e";
			bool foundStartChar = false, foundEndChar = false;

			Assert::AreEqual(findCharacters(inputFile, startString, endString, foundStartChar, foundEndChar), false);

			inputFile.close();
		}
	};
}