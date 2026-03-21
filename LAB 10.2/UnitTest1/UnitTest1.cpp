#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

#include "D:\LAB 10.2\Project1\Source.cpp"

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestCapitalizeFirstLetter)
		{
			string input = "hello";
			string expected = "Hello";

			string result = capitalizeFirstLetter(input);

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestAlreadyCapitalized)
		{
			string input = "World";
			string result = capitalizeFirstLetter(input);

			Assert::AreEqual(string("World"), result);
		}
		TEST_METHOD(TestProcessFileBasic)
		{
			string inputFile = "test_input.txt";
			string outputFile = "test_output.txt";

			ofstream fin(inputFile);
			fin << "hello world. this is test.";
			fin.close();

			bool success = processFile(inputFile, outputFile);

			Assert::IsTrue(success);

			ifstream fout(outputFile);
			string result, line;
			while (getline(fout, line))
			{
				result += line;
			}
			fout.close();

			string expected = "hello world. This is test.";

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestMultipleSentences)
		{
			string inputFile = "test_input2.txt";
			string outputFile = "test_output2.txt";

			ofstream fin(inputFile);
			fin << "one. two. three.";
			fin.close();

			processFile(inputFile, outputFile);

			ifstream fout(outputFile);
			string result, line;
			while (getline(fout, line))
			{
				result += line;
			}
			fout.close();

			string expected = "one. Two. Three.";

			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestNoDots)
		{
			string inputFile = "test_input3.txt";
			string outputFile = "test_output3.txt";

			ofstream fin(inputFile);
			fin << "hello world without dots";
			fin.close();

			processFile(inputFile, outputFile);

			ifstream fout(outputFile);
			string result, line;
			while (getline(fout, line))
			{
				result += line;
			}
			fout.close();

			string expected = "hello world without dots";

			Assert::AreEqual(expected, result);
		}
	};
}
