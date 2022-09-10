#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    cout << "Input your name, surname and favorite film" << "\n";
    string name, surname, film;
    cin >> name >> surname >> film;

    ofstream f("info.txt");
    f << name << " " << surname << " " << film << "\n";
}




