#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int nextpossible(int n, vector<int>& height) {
    int i = n + 1; 
    while (i < height.size() && height[n] <= height[i]) {
        i++;
    }
    return i - 1; 
}

int prevpossible(int n, vector<int>& height) {
    int i = n - 1; 
    while (i >= 0 && height[n] >= height[i]) {
        i--;
    }
    return i + 1; 
}

int maxareaofrectangle(vector<int>& height) {
    int area = 0;
    for (int i = 0; i < height.size(); i++) {
        int width = nextpossible(i, height) - prevpossible(i, height) + 1;
        int newarea = width * height[i];
        area = max(area, newarea);
    }
    return area;
}

int main() {
    vector<vector<int>> binarymatrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };     
    int n = binarymatrix.size();
    int m = binarymatrix[0].size();
    vector<int> height(m, 0); 
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            height[j] = (binarymatrix[i][j] == 0) ? 0 : height[j] + 1; 
        }
    }

    int area = maxareaofrectangle(height);
    cout << "Largest rectangular area in binary matrix is: " << area << endl;
    
    return 0;
}
