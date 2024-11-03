#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool knows(const vector< vector<int> >& matrix, int a, int b) {
    return matrix[a][b] == 1;
}

int main() {
    vector< vector<int> > matrix = { 
        {0, 0, 1, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 1, 0} 
    };
    int n = 4;
    stack<int> temp;

    // Push all people onto the stack
    for (int i = 0; i < n; i++) {
        temp.push(i);
    }

    // Find the potential celebrity
    while (temp.size() > 1) {
        int a = temp.top();
        temp.pop();
        int b = temp.top();
        temp.pop();
        if (knows(matrix, a, b)) {
            temp.push(b); 
        } else {
            temp.push(a);  
        }
    }

    // The potential celebrity
    int j = temp.top();
    bool rowcheck = true;  
    bool columncheck = true;  

    // Verifying with the help of column
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] == 0 && i != j) {
            columncheck = false;
            break;
        }
    }

    // Verifying with the help of row
    for (int i = 0; i < n; i++) {
        if (matrix[j][i] != 0) {
            rowcheck = false;
            break;
        }
    }

    // Check if both row and column checks are valid
    if (rowcheck && columncheck) {
        cout << j << ", is the celebrity element" << endl;
    } else {
        cout << "No celebrity found" << endl;  
    }

    return 0;
}
