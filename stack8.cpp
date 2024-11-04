#include<iostream>
#include <vector>
using namespace std;

class Nstack {
private:
    int *arr;
    int *top;
    int *next;
    int freespot;
    int stacknum_;
    int size;

public:
    Nstack(int size, int stacknum_) {
        this->size = size;
        this->stacknum_ = stacknum_;
        arr = new int[size];
        top = new int[stacknum_];
        next = new int[size];
        freespot = 0;

       
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
            next[i] = i + 1; 
        }
        next[size - 1] = -1; 
        for (int i = 0; i < stacknum_; i++) {
            top[i] = -1; 
        }
    }

    void push(int element, int stacknum) {
        if (stacknum < stacknum_ && stacknum >= 0) {
            if (freespot == -1) {
                cout << "Stack overflow!!!" << endl;
                return;
            }

            int index = freespot; 
            freespot = next[index]; 
            arr[index] = element; 
            
            next[index] = top[stacknum];
            top[stacknum] = index; 

            cout << "Element " << element << " is successfully pushed into stack number: " << stacknum << endl;
        } else {
            cout << "Invalid stack number!!! Note that stack num is 0 to inputNumberOfStacks-1" << endl;
        }
    }

    void pop(int stacknum) {
        if (stacknum < stacknum_ && stacknum >= 0) {
            int index = top[stacknum]; 
            if (index != -1) { 
                top[stacknum] = next[index]; 
                next[index] = freespot; 
                freespot = index; 
                cout << "Element at stack number " << stacknum << " is popped." << endl;
            } else {
                cout << "Stack " << stacknum << " is empty!" << endl;
            }
        } else {
            cout << "Invalid stack number!!! Note that stack num is 0 to inputNumberOfStacks-1" << endl;
        }
    }

    void peek(int stacknum) {
        if (stacknum < stacknum_ && stacknum >= 0) {
            int index = top[stacknum]; 
            if (index != -1) { 
                int element = arr[index]; 
                cout << "Element at top of stack number " << stacknum << " is: " << element << endl;
            } else {
                cout << "Stack " << stacknum << " is empty!" << endl;
            }
        } else {
            cout << "Invalid stack number!!! Note that stack num is 0 to inputNumberOfStacks-1" << endl;
        }
    }

    ~Nstack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main() {
    Nstack array(100, 20);

    array.push(10, 0);
    array.push(20, 10);
    array.peek(0); 
    array.pop(0);
    array.peek(0); 
    array.pop(0);

}
