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
    fstream q("questions.txt"), f;
    f.open("info.txt", ios_base::app);
    string questionLine, name, surname, answer, _;

    cout << "Input your name and surname:\n";
    cin >> name >> surname;
    f << name << ", " << surname;
    getline(cin, _);

    cout << "Please answer the following questions:\n";
    while (getline(q, questionLine))
    {
        cout << questionLine << "\n";
        getline(cin, answer);
        f << ", " << answer;
    }

    f << ";\n";


    q.close();
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


