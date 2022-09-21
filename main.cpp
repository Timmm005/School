#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;


void printInfo()
{
    ifstream f("info.txt");
    string line, word, popBook;
    int n = 0;
    map<string, int> bookPopularity = {};

    cout << "Name | Surname | Info\n";
    while (getline(f, line))
    {
        stringstream stream(line);
        int counter = 0;
        n++;

        while (getline(stream, word, ','))
        {
            if (counter <= 1)//name | surname |
            {
                cout << word << " |";
                counter++;
            }

            else if (counter == 2) //first question is abt the book
            {
                cout << word;
                counter++;
                string book = word.substr(1);
                bookPopularity[book]++;
                if (bookPopularity[book] >= bookPopularity[popBook]) { popBook = book; }
            }

            else { cout << "," << word; }
        }
        cout << "\n";

    }
    f.close();
    cout << "\n";
    cout << "Total number of people: " << n << "\n";
    cout << "The most popular book is " << "'" << popBook << "'" << " with " << bookPopularity[popBook] << " likes";
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


