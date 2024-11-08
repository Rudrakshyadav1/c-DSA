#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    int arr[6] = {-1, -2, 69,34, -4, 2};
    int k;
    deque<int> dq;
    vector<int> ans;
    
    cout << "Enter the size of window (<= 5): ";
    cin >> k;
    for (int i = 0; i < k; i++){
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }
    if (!dq.empty()){
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }
    for (int i = k; i < 6; i++) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        if (arr[i] < 0) {
            dq.push_back(i);
        }
        if (!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
