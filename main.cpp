#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    cout << "Input your name, surname, a book that you would like to recommend, as well as a political party you are planning to vote for" << "\n";
    string name, surname, book, party;
    cin >> name >> surname >> book >> party;

    ofstream f("info.txt");
    f << name << " " << surname << " " << book << " " << party << "\n";
}




