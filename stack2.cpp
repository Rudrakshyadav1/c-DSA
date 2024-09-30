#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool check(string str){
    stack<char> s;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '('){
            s.push(str[i]);
        } else{
            if (s.empty()) {
                cout << "unbalanced brackets:" << endl;
                return false;
            }
            if (s.top() == '{' && str[i] == '}'){
                s.pop();
            } else if (s.top() == '[' && str[i] == ']'){
                s.pop();
            } else if (s.top() == '(' && str[i] == ')'){
                s.pop();
            } else {
                cout << "unbalanced brackets:" << endl;
                return false;
            }
        }
    }
    if (s.empty()){
        cout << "balanced brackets:" << endl;
        return true;
    } else{
        cout << "unbalanced brackets:" << endl;
        return false;
    }
}

int main(){
    string str = "[{{{[()]}}}]";
    check(str);
    return 0;
}