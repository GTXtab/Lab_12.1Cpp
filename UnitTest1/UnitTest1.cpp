#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "../Project1/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(PrintBIN_Test)
		{
			// ��'� ��������� �����
			char testFileName[] = "test_file.dat";

			// ��������� ����� � ��������� ������
			ofstream fout(testFileName, ios::binary);
			int testData[] = { 1, 2, 3, 4 };
			for (int num : testData) {
				fout.write((char*)&num, sizeof(num));
			}
			fout.close();

			// ���������� ������ cout
			stringstream buffer;
			streambuf* oldCout = cout.rdbuf(buffer.rdbuf()); // ������� ���� ������

			// ������ �������
			PrintBIN(testFileName);

			// ³��������� ������ ������
			cout.rdbuf(oldCout);

			// ���������� ����
			string expectedOutput = "File content (test_file.dat):\n1 2 3 4 \n";

			// ��������
			Assert::AreEqual(expectedOutput, buffer.str(), L"Output does not match expected result.");

			// ��������� ��������� �����
			remove(testFileName);
		}
	};
}
