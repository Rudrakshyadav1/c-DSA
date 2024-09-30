#include <iostream>
using namespace std;

bool ispossible(int a[], int mid, int n, int k) {
    int stu = 1;
    int pages = 0;
    for (int i = 0; i < k; i++) {
        if (pages + a[i] <= mid) {
            pages += a[i];
        } else {
            stu++;
            pages = a[i];
        }
    }
    return stu <= n;
}

int book_allocation(int a[], int p, int sum, int n, int k) {
    if (n > k) {
        return -1; 
    }
    int s = p;
    int e = sum;
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (ispossible(a, mid, n, k)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "enter the number of students: ";
    cin >> n;
    int a[] = {10, 5, 60, 90, 100, 120, 40, 60};
    int k = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    int p = INT_MIN;
    for (int i = 0; i < k; i++) {
        if (p < a[i]) {
            p = a[i];
        }
    }
    int result = book_allocation(a, p, sum, n, k);
    if (result == -1) {
        cout << "Not possible to allocate books." << endl;
    } else {
        cout << "Minimum possible maximum number of pages: " << result << endl;
    }
    return 0;
}
