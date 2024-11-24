#include <iostream>
#include <fstream>

using namespace std;

// ������� ��� ��������� �����
void CreateBIN(char* fname) {
    ofstream fout(fname, ios::binary);
    char ch;
    int num;

    do {
        cout << "Enter a number: ";
        cin >> num;
        fout.write((char*)&num, sizeof(num)); // ����� ����� � ����

        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fout.close();
}

// ������� ��� ��������� �����
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

// ������� ��� ������� �����
void ProcessBIN(char* fname, char* gname) {
    ifstream fin(fname, ios::binary);
    ofstream fout(gname, ios::binary);

    int num, sum = 0;

    while (fin.read((char*)&num, sizeof(num))) {
        sum += num; // ���������� �������������� ����
        fout.write((char*)&sum, sizeof(sum)); // ����� ���� � ����
    }

    fin.close();
    fout.close();
}

int main() {
    char fname[100], gname[100];

    // ��������� �� ��������� ������� �����
    cout << "Enter file name 1: ";
    cin >> fname;
    CreateBIN(fname);
    PrintBIN(fname);

    // ������� ������� ����� �� ����� ���������� � ������ ����
    cout << "Enter file name 2: ";
    cin >> gname;
    ProcessBIN(fname, gname);

    // ��������� ������� �����
    PrintBIN(gname);

    return 0;
}
