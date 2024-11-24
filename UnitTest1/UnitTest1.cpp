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
			// Ім'я тестового файлу
			char testFileName[] = "test_file.dat";

			// Створення файлу з тестовими даними
			ofstream fout(testFileName, ios::binary);
			int testData[] = { 1, 2, 3, 4 };
			for (int num : testData) {
				fout.write((char*)&num, sizeof(num));
			}
			fout.close();

			// Захоплення виводу cout
			stringstream buffer;
			streambuf* oldCout = cout.rdbuf(buffer.rdbuf()); // Змінюємо потік виводу

			// Виклик функції
			PrintBIN(testFileName);

			// Відновлення потоку виводу
			cout.rdbuf(oldCout);

			// Очікуваний вивід
			string expectedOutput = "File content (test_file.dat):\n1 2 3 4 \n";

			// Перевірка
			Assert::AreEqual(expectedOutput, buffer.str(), L"Output does not match expected result.");

			// Видалення тестового файлу
			remove(testFileName);
		}
	};
}
