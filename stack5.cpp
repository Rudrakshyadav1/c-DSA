#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> previousMaximum(int a[], int n){
    vector<int> prev(n);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return prev;
}
vector<int> nextMaximum(int a[], int n){
    vector<int> next(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return next;
}
int maxAreaRectangleHistogram(int a[], int n){
    vector<int> prev = previousMaximum(a, n);
    vector<int> next = nextMaximum(a, n);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int width = next[i] - prev[i] - 1; 
        int area = width * a[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main(){
    int a[] = {2, 20, 10, 70, 90, 1, 3, 5};
    int n = sizeof(a) / sizeof(a[0]); 
    int ans = maxAreaRectangleHistogram(a, n);
    cout << "The maximum rectangular area possible in the given histogram is: " << ans << endl;

    return 0;
}
