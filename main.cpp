#include <iostream>
#include <fstream>
using namespace std;


void printInfo()
{
    ifstream f("info.txt");
    string line;

    while (getline(f, line))
    {
        cout << line << "\n";
    }
    f.close();
}



void readInfo()
{
    cout << "Input your name, surname and a book that you would like to recommend" << "\n";
    string name, surname, book;
    cin >> name >> surname >> book;

    ofstream f;
    f.open("info.txt", ios_base::app);

    f << "\n" << name << " " << surname << " " << book;
    f.close();
}


int main()
{
    readInfo();
    //printInfo();
}