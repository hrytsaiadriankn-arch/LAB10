#include "pch.h"
#include "CppUnitTest.h"

#include "D:\LAB 10.3\Project1\Source.cpp"

#include <fstream>
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFriends
{
	TEST_CLASS(UnitTestFriends)
	{
	public:

		TEST_METHOD(TestWriteAndReadFile)
		{
			ofstream fout("test.txt");
			fout << "Ivanenko Ivan 123456 1 1 2000\n";
			fout.close();

			ifstream fin("test.txt");

			Friend f;
			fin >> f.surname >> f.name >> f.phone >> f.day >> f.month >> f.year;

			Assert::AreEqual("Ivanenko", f.surname.c_str());
			Assert::AreEqual("Ivan", f.name.c_str());
			Assert::AreEqual("123456", f.phone.c_str());
			Assert::AreEqual(1, f.day);
			Assert::AreEqual(1, f.month);
			Assert::AreEqual(2000, f.year);

			fin.close();
		}
	};
}