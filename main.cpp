#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    cout << "Input your name, surname and a book that you would like to recommend" << "\n";
    string name, surname, book;
    cin >> name >> surname >> book;

    ofstream f("info.txt");
    f << name << " " << surname << " " << book << "\n";
}




