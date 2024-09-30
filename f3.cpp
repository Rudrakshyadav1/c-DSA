#include <iostream>
using namespace std;

int fac(int x) {
   if (x == 1 || x == 0) return 1;
   return x * fac(x - 1);
}

int main() {  
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Factorial of " << n << " is: " << fac(n) << endl;
   }
   