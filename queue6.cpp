#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<char> q;          
    string str = "aaabbcc";  
    string answer = "";       
    int count[26] = {0};      

    for (int i = 0; i < str.length(); i++) {
        char temp = str[i];
        count[temp - 'a']++;  
        q.push(temp);          

        while (!q.empty()) {
            if (count[q.front() - 'a'] > 1) {
                q.pop();   
            } else {
                answer.push_back(q.front());  
                break;
            }
        }
        if (q.empty()) {
            answer.push_back('#');
        }
    }
    cout << answer << endl;

    return 0;
}
