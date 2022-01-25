#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <istream>

using namespace std;

string text;
int counter = 0;

void inFunc(string path) {
    ifstream fin;
    fin.open(path);
    if(!fin.is_open()) {
        cout << "Error" << endl;
    } else {
        if (counter < 1) {
            cout << "File is open" << endl;
        }
        string line;
        while (!fin.eof()) {
            getline(fin, line);
            text += line + "\n";
        }
        cout << endl;
    }
    fin.close();
}

void outFunc(string path) {
    ofstream fout;
    fout.open(path);
    if(!fout.is_open()) {
        cout << "Error" << endl;
    } else {
        cout << "File is written " << counter+1 << " times" << endl;
        fout << "";
        text += "File updated " + to_string(++counter) + " times";
        fout << text;
        cout << endl;
    }
    text = "";
    fout.close();
}

void fileReader(string inputPath, string outputPath) {
    inFunc(inputPath);
    outFunc(outputPath);
}

int main()
{
    int time;
    string inputPath, outputPath;
    cout << "To close app press Enter" << endl;
    cout << "Write a time in ms: ";
    cin >> time;
    cout << "" << endl;
    cout << "Write an input file path: ";
    cin >> inputPath;
    cout << "" << endl;
    cout << "Write an output file path: ";
    cin >> outputPath;
    cout << "" << endl;

    while (true) {
        if (_kbhit())
            if (_getch() == '\r')
                break;
        fileReader(inputPath, outputPath);
        Sleep(time);
        counter++;
    };
    return 0;
}
