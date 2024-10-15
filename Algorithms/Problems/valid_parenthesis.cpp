#include <iostream>
#include <stack>

using namespace std;

char matchingParenthesis(char c) {
    if(c == '{')
    return '}';
    else if(c== '(')
    return ')';
    else if(c=='[')
    return ']';

    return '\0';
}

bool checkForValidParenthesis(string s) {
    stack<char> charStack;

    for(int i=0; i<s.length(); i++) {
        char character = (char)s[i];
        

        if(character == '{' || character == '[' || character == '(') {
              charStack.push(character);  
        }
        else if(character == '}' || character == ']' || character == ')') {
              if(charStack.empty() || matchingParenthesis(charStack.top())!=character) {
                return false;
              }

              charStack.pop();
        }
    }

    return charStack.empty();
}

int main(int argc, char** argv) {
    string s = "[{()}]";

    if(argc>1) {
        s = argv[1];
    }

    cout << checkForValidParenthesis(s) << endl;
}