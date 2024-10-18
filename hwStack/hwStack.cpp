#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool Brackets(char first, char last) 
{
    return (first == '(' && last == ')') || (first == '{' && last == '}') || (first == '[' && last == ']');
}

void СheckBrackets(const string& str) 
{
    stack<char> brackets;
    for (size_t i = 0; i < str.size(); ++i) 
    {
        char checkbr = str[i];
        if (checkbr == '(' || checkbr == '{' || checkbr == '[') 
        {
            brackets.push(checkbr);
        }
        else if (checkbr == ')' || checkbr == '}' || checkbr == ']') 
        {
            if (brackets.empty() || !Brackets(brackets.top(), checkbr)) 
            {
                cout << "Error at " << i + 1 << " place: " << str.substr(0, i + 1) << endl;
                return;
            }
            brackets.pop(); 
        }
        if (checkbr == ';' && i == str.size() - 1) 
        {
            if (brackets.empty()) 
            {
                cout << "Good" << endl;
            }
            else 
            {
                cout << "Bad" << endl;
            }
            return;
        }
    }
    cout << "Where is \";\"?" << endl;
}

int main() {
    string a;
    cout << "Enter: ";
    getline(cin, a);
    СheckBrackets(a);
    return 0;
}

