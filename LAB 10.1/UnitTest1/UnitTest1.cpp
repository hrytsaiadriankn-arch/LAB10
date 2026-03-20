#include "pch.h"
#include "CppUnitTest.h"

#include "D:\LAB 10.1\Project1\Source.cpp"

#include <fstream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDots
{
	TEST_CLASS(UnitTestDots)
	{
	public:

		TEST_METHOD(TestThirdDotFound)
		{
			ofstream fout("test1.txt");
			fout << "abc.def.ghi.jkl";
			fout.close();

			Result r = findThirdDot("test1.txt");

			Assert::IsTrue(r.found);
			Assert::AreEqual(1, r.line);
			Assert::AreEqual(12, r.position); // третя крапка
			Assert::AreEqual(3, r.dotCount);
		}

		TEST_METHOD(TestLessThanThreeDots)
		{
			ofstream fout("test2.txt");
			fout << "abc.def";
			fout.close();

			Result r = findThirdDot("test2.txt");

			Assert::IsFalse(r.found);
			Assert::AreEqual(2, r.dotCount);
		}

		TEST_METHOD(TestNoDots)
		{
			ofstream fout("test3.txt");
			fout << "abcdefg";
			fout.close();

			Result r = findThirdDot("test3.txt");

			Assert::IsFalse(r.found);
			Assert::AreEqual(0, r.dotCount);
		}

		TEST_METHOD(TestMultipleLines)
		{
			ofstream fout("test4.txt");
			fout << "abc.\n";
			fout << "def.\n";
			fout << "ghi.\n";
			fout.close();

			Result r = findThirdDot("test4.txt");

			Assert::IsTrue(r.found);
			Assert::AreEqual(3, r.line);
			Assert::AreEqual(4, r.position);
			Assert::AreEqual(3, r.dotCount);
		}

		TEST_METHOD(TestFileNotFound)
		{
			Result r = findThirdDot("no_such_file.txt");

			Assert::IsFalse(r.found);
			Assert::AreEqual(0, r.dotCount);
		}
	};
}

