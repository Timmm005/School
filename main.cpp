#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void updateQuestions() {
    int quesCnt;
    cout << "Enter questions count\n";
    cin >> quesCnt;

    cout << "Enter questions in format:\n";
    cout << "[question]; [answer type]\n";
    cout << "Example: What's your name?; name\n";

    fstream qOut("questions.txt");
    string ques;
    getline(cin, ques);
    while (quesCnt--) {
        getline(cin, ques);
        qOut << ques << "\n";
    }
}

void printInfo(int width)
{
    if (width < 37)
    {
        cout << "width was increased to fit minimal information\n";
        width = 37;
    }

    ifstream f("info.txt");
    string line, word, popBook;
    string emp = "               ";
    int n = 0;
    map<string, int> bookPopularity = {};

    cout << "Name    |    Surname    |    Info    \n";
    cout << "-------------------------------------\n";
    while (getline(f, line))
    {
        stringstream stream(line);
        int counter = 0;
        n++;
        int remWidth = width - 25; //this is first used in the INFO part (25 comes from name+surname)

        while (getline(stream, word, ','))
        {
            if (counter == 0)//name   |
            {
                if (word.length() > 8) { cout << word.substr(0, 7) << ".|"; }
                else { cout << word << emp.substr(0, 8 - word.length()) << "|"; }
                counter++;
            }


            else if (counter == 1)//   surname   |
            {
                if (word.length() > 15) { cout << word.substr(0, 14) << ".|"; }
                else { cout << word << emp.substr(0, 15 - word.length()) << "|"; }
                counter++;
            }


            else if (counter == 2) //first question is abt the book
            {
                if (remWidth == 0) {}
                else if (remWidth <= 3) { cout << "..."; }
                else if (word.length() > remWidth)
                {
                    cout << word.substr(0, remWidth - 3) << "...";
                    remWidth = 0;
                }
                else
                {
                    cout << word;
                    remWidth -= word.length();
                }

                counter++;
                string book = word.substr(1);
                bookPopularity[book]++;
                if (bookPopularity[book] >= bookPopularity[popBook]) { popBook = book; }
            }


            else
            {
                if (remWidth == 0) {}
                else if (remWidth <= 3) { cout << "..."; }
                else if (word.length() > remWidth)
                {
                    cout << "," << word.substr(0, remWidth - 3) << "...";
                    remWidth = 0;
                }
                else
                {
                    cout << "," << word;
                    remWidth -= word.length();
                }
            }
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
    string questionLine, name, surname, answer, _, question, qKeyword;

    cout << "Input your name and surname:\n";
    cin >> name >> surname;
    f << name << ", " << surname;
    getline(cin, _);


    cout << "Please answer the following questions:\n";
    while (getline(q, questionLine))
    {
        auto index = questionLine.find(";");
        question = questionLine.substr(0, index);
        qKeyword = questionLine.substr(index + 2); //extra ; and a space

        cout << question << "\n";
        getline(cin, answer);
        f << ", " << qKeyword << "=" << answer;
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
    cout << "3) Rewrite questions\n";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        readInfo();
        break;

    case 2:
        printInfo(66);
        break;

    case 3:
        updateQuestions();
        break;

    default:
        cout << "Not a valid option";
        break;
    }
}


