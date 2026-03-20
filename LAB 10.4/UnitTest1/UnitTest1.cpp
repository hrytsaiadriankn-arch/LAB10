#include "pch.h"
#include "CppUnitTest.h"

#include "D:\LAB 10.4\Project1\Source.cpp"

#include <vector>
#include <string>
#include <fstream>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMeans
{
	TEST_CLASS(UnitTestMeans)
	{
	public:

		TEST_METHOD(TestIsNumber)
		{
			Assert::IsTrue(isNumber("123"));
			Assert::IsTrue(isNumber("-5.2"));
			Assert::IsFalse(isNumber("abc"));
		}

		TEST_METHOD(TestExtractNumbers)
		{
			string line = "a 10 20.5 b -3";

			vector<double> nums = extractNumbers(line);

			Assert::AreEqual(3, (int)nums.size());
			Assert::AreEqual(10.0, nums[0]);
			Assert::AreEqual(20.5, nums[1]);
			Assert::AreEqual(-3.0, nums[2]);
		}

		TEST_METHOD(TestArithmeticMean)
		{
			vector<double> nums = { 2, 4, 6 };

			double result = calculateArithmeticMean(nums);

			Assert::AreEqual(4.0, result);
		}

		TEST_METHOD(TestGeometricMean)
		{
			vector<double> nums = { 1, 4, 9 };

			double result = calculateGeometricMean(nums);

			Assert::AreEqual(3.3019, result, 0.0001);
		}

		TEST_METHOD(TestGeometricMeanInvalid)
		{
			vector<double> nums = { 1, -2, 3 };

			double result = calculateGeometricMean(nums);

			Assert::AreEqual(0.0, result);
		}

	};
}