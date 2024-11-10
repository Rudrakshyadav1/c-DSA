#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> maximum;  
    deque<int> minimum;  
    int arr[] = {10, -100, 90, 85, 43, 69, -70};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k;
    cout << "Enter the window size: ";
    cin >> k;
    if (k > n) {
        cout << "Window size is greater than the array size!" << endl;
        return 0;
    }
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        if (!maximum.empty() && maximum.front() <= i - k) {
            maximum.pop_front();
        }
        if (!minimum.empty() && minimum.front() <= i - k) {
            minimum.pop_front();
        }
        while (!maximum.empty() && arr[maximum.back()] <= arr[i]) {
            maximum.pop_back();
        }
        maximum.push_back(i);
        while (!minimum.empty() && arr[minimum.back()] >= arr[i]) {
            minimum.pop_back();
        }
        minimum.push_back(i);
        if (i >= k - 1) {
            sum += arr[maximum.front()] + arr[minimum.front()];
        }
    }
    cout << "Sum of minimum and maximum elements of all subarrays of size " << k << " is: " << sum << endl;
    return 0;
}
