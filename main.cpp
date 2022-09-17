#include <iostream>
#include <fstream>
#include <sstream>
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
    cout << "Select an option (int):\n";
    cout << "1) Read user's info\n";
    cout << "2) Print the saved info\n";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        readInfo();
        break;

    case 2:
        printInfo();
        break;

    default:
        cout << "Not a valid option";
        break;
    }
}