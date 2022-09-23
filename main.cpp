#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;


void updateQuestions() {
    int quesCnt;
    cout << "Enter questions count\n";
    cin >> quesCnt;
    if (quesCnt < 0) { quesCnt = 0; }

    cout << "Enter questions in format:\n";
    cout << "[question]; [answer type]\n";
    cout << "Example: What's your name?; name\n";
    cout << "\n";

    ofstream qOut;
    qOut.open("questions.txt", ofstream::out | ofstream::trunc);
    string ques;
    getline(cin, ques);
    while (quesCnt--) {
        cout << "Enter new question:\n";
        getline(cin, ques);
        while (ques.find("; ") == string::npos)
        {
            cout << "Your question does not fit the format, input it correctly:\n";
            getline(cin, ques);
        }
        qOut << ques << "\n";
    }

    ofstream info;
    info.open("info.txt", ofstream::out | ofstream::trunc);
    info.close();

    cout << "\n";
    cout << "Questions were changed\n";
    cout << "info.txt was cleared\n";
}



string getColumnString(string str, int columnWidth)
{
    if (str.length() > columnWidth)
    {
        string newStr = str.substr(0, columnWidth - 3);
        newStr.append("...");
        return newStr;
    }

    else
    {
        string newStr = str;
        while (newStr.length() < columnWidth) { newStr.append(" "); }
        return newStr;
    }
}


void printInfo()
{
    ifstream f("info.txt"), q("questions.txt");
    string line, word, popBook, qLine;
    vector<string> qKeywords;
    int n = 0;
    int nQ = 0;
    map<string, int> bookPopularity = {};

    while (getline(q, qLine))
    {
        string keyword = qLine.substr(qLine.find(";") + 1);
        qKeywords.push_back(keyword);
        nQ++;
    }


    cout << "Input the width of the table\n";
    int width, columnWidth;
    int const minColumnWidth = 5;
    cin >> width;
    width--;
    columnWidth = width / (nQ + 2) - 1;

    while (columnWidth < minColumnWidth)
    {
        cout << "Input the width of the table (>= " << (minColumnWidth + 1) * (nQ + 2) + 1 << ")\n";
        cin >> width;
        width--;
        columnWidth = width / (nQ + 2) - 1;
    }

    cout << "|" << getColumnString(" name", columnWidth) << "|" << getColumnString(" surname", columnWidth) << "|";

    int bookKwNumber = -1;
    int counter = 0;
    for (string kw : qKeywords)
    {
        cout << getColumnString(kw, columnWidth) << "|";
        if (kw == " book") { bookKwNumber = counter; }
        counter++;
    }
    cout << "\n";

    counter = 0;
    while (counter <= (columnWidth + 1) * (nQ + 2)) { cout << "-"; counter++; }
    cout << "\n";

    while (getline(f, line))
    {
        stringstream stream(line);
        int counter = 0;
        n++;

        while (getline(stream, word, ','))
        {
            if (counter == 0)//name
            {
                cout << "| " << getColumnString(word, columnWidth - 1) << "|";
            }

            else if (counter == 1)//surname
            {
                cout << getColumnString(word, columnWidth) << "|";
            }

            else { cout << getColumnString(word, columnWidth) << "|"; } // Info


            if ((counter - 2) == bookKwNumber)
            {
                string book = word.substr(1);
                bookPopularity[book]++;
                if (bookPopularity[book] >= bookPopularity[popBook]) { popBook = book; }
            }

            counter++;


        }
        cout << "\n";

    }
    f.close();
    q.close();
    cout << "\n";

    cout << "Total number of people: " << n << "\n";
    if (bookKwNumber != -1)
    {
        cout << "The most popular book is " << "'" << popBook << "'" << " with " << bookPopularity[popBook] << " likes";
    }

    else
    {
        cout << "Could not find the best book because that question is missing\n";
    }
    cout << "\n";
}



void readInfo()
{
    fstream q("questions.txt"), f;
    f.open("info.txt", ios_base::app);
    string questionLine, name, surname, answer, _;

    cout << "Input your name and surname:\n";
    cin >> name >> surname;
    while (name.find(",") != string::npos) { cout << "Symbol ',' is unavailable, enter your NAME again:\n"; cin >> name; }
    while (surname.find(",") != string::npos) { cout << "Symbol ',' is unavailable, enter your SURNAME again:\n"; cin >> surname; }

    f << name << ", " << surname;
    getline(cin, _);

    cout << "Please answer the following questions:\n";
    while (getline(q, questionLine))
    {
        cout << questionLine.substr(0, questionLine.find(";")) << "\n";
        getline(cin, answer);
        while (answer.find(",") != string::npos)
        {
            cout << "Symbol ',' is unavailable, answer again\n";
            getline(cin, answer);
        }
        f << ", " << answer;
    }

    f << "\n";


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
        printInfo();
        break;

    case 3:
        updateQuestions();
        break;

    default:
        cout << "Not a valid option";
        break;
    }
}



