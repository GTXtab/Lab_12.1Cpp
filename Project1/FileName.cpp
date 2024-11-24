#include <iostream>
#include <fstream>

using namespace std;

// Функція для створення файлу
void CreateBIN(char* fname) {
    ofstream fout(fname, ios::binary);
    char ch;
    int num;

    do {
        cout << "Enter a number: ";
        cin >> num;
        fout.write((char*)&num, sizeof(num)); // Запис числа у файл

        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fout.close();
}

// Функція для виведення файлу
void PrintBIN(char* fname) {
    ifstream fin(fname, ios::binary);
    int num;

    cout << "File content (" << fname << "):" << endl;
    while (fin.read((char*)&num, sizeof(num))) {
        cout << num << " ";
    }
    cout << endl;

    fin.close();
}

// Функція для обробки файлу
void ProcessBIN(char* fname, char* gname) {
    ifstream fin(fname, ios::binary);
    ofstream fout(gname, ios::binary);

    int num, sum = 0;

    while (fin.read((char*)&num, sizeof(num))) {
        sum += num; // Обчислення накопичувальної суми
        fout.write((char*)&sum, sizeof(sum)); // Запис суми у файл
    }

    fin.close();
    fout.close();
}

int main() {
    char fname[100], gname[100];

    // Створення та виведення першого файлу
    cout << "Enter file name 1: ";
    cin >> fname;
    CreateBIN(fname);
    PrintBIN(fname);

    // Обробка першого файлу та запис результату у другий файл
    cout << "Enter file name 2: ";
    cin >> gname;
    ProcessBIN(fname, gname);

    // Виведення другого файлу
    PrintBIN(gname);

    return 0;
}
