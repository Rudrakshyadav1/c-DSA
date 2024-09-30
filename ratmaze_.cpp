//RAT IN MAZE PROBLEM...
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool issafe(int newx, int newy, int maze[4][4], int v_[4][4]) {
    if ((newx >= 0 && newx < 4) && (newy >= 0 && newy < 4) && maze[newx][newy] == 1 && v_[newx][newy] == 0) {
        return true;
    }
    else {
        return false;
    }
}

void path(int x, int y, vector<string>& ans, int maze[4][4], int v_[4][4], string p_) {
    if (x == 3 && y == 3) {
        ans.push_back(p_);
        return;
    }
    v_[x][y] = 1;
    // possible moves UP,DOWN,LEFT,RIGHT
    // DOWN
    int newx = x + 1;
    int newy = y;
    if (issafe(newx, newy, maze, v_)) {
        p_.push_back('D');
        path(newx, newy, ans, maze, v_, p_);
        p_.pop_back();
    }
    // Left
    newx = x;
    newy = y - 1;
    if (issafe(newx, newy, maze, v_)) {
        p_.push_back('L');
        path(newx, newy, ans, maze, v_, p_);
        p_.pop_back();
    }
    // Right
    newx = x;
    newy = y + 1;
    if (issafe(newx, newy, maze, v_)) {
        p_.push_back('R');
        path(newx, newy, ans, maze, v_, p_);
        p_.pop_back();
    }
    // UP
    newx = x - 1;
    newy = y;
    if (issafe(newx, newy, maze, v_)) {
        p_.push_back('U');
        path(newx, newy, ans, maze, v_, p_);
        p_.pop_back();
    }
    v_[x][y] = 0;
}

int main() {
    // creating maze 
    int v_[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    int maze[4][4] = {
        {1, 0, 1, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 0, 1}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    int srcx = 0;
    int srcy = 0;
    vector<string> ans;
    string p_ = "";
    if (maze[0][0] == 0) {
        cout << "NO POSSIBLE PATHS";
    }
    else {
        path(srcx, srcy, ans, maze, v_, p_);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
   } 

   