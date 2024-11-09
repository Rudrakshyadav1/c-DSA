#include <iostream>
using namespace std;

class Kqueue {
private:
    int *arr;
    int *next;
    int *front;
    int *rear;
    int size;
    int freespot;
    int k;

public:
    Kqueue(int size, int k) {
        this->size = size;
        this->k = k;
        arr = new int[size];
        next = new int[size];
        front = new int[k];
        rear = new int[k];
        freespot = 0;
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
            next[i] = i + 1;
        }
        next[size - 1] = -1;  
        
        for (int i = 0; i < k; i++) {
            front[i] = -1;  
            rear[i] = -1; 
        }
    }
    bool isempty(int n) {
        return (front[n] == -1);
    }
    bool isfull() {
        return (freespot == -1);
    }
    void push(int n, int element) {
        if (isfull()) {
            cout << "No more elements can be inserted. Queue is full.\n";
            return;
        }

        int index = freespot;  
        freespot = next[freespot]; 
        arr[index] = element; 

        if (front[n] == -1) {  
            front[n] = index;   
            rear[n] = index;    
        } else {  
            next[rear[n]] = index;  
            rear[n] = index;     
        }
        next[index] = -1;  
        cout << "Element " << element << " pushed successfully to queue " << n << ".\n";
    }

   
    void pop(int n) {
        if (isempty(n)) {
            cout << "Queue " << n << " is empty. No element to pop.\n";
            return;
        }
        int index = front[n]; 
        front[n] = next[front[n]];  
        if (front[n] == -1) { 
            rear[n] = -1; 
        }
        next[index] = freespot;  
        freespot = index; 

        arr[index] = 0;  
        cout << "Element " << arr[index] << " popped successfully from queue " << n << ".\n";
    }
    void peek(int n) {
        if (isempty(n)) {
            cout << "Queue " << n << " is empty. No element to peek.\n";
            return;
        }
        cout << "Peeked element from queue " << n << ": " << arr[front[n]] << "\n";
    }
    ~Kqueue() {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};

int main() {
    //Tests:-
    // Create a Kqueue with size 10 and 3 sub-queues
    Kqueue kq(10, 3);
    // Test: Push elements into different queues
    kq.push(0, 10);
    kq.push(0, 20);
    kq.push(1, 30);
    kq.push(2, 40);
    // Test: Peek elements from each queue
    kq.peek(0);
    kq.peek(1);
    kq.peek(2);
    // Test: Pop elements from each queue
    kq.pop(0);
    kq.pop(1);
    kq.pop(2);
    // Test: Check empty queues
    kq.pop(0);
    kq.peek(0);

    return 0;
}
