#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = 0; 
    }

    void push(int element) {
        if (isfull()) {
            cout << "Pushing more elements not possible!!!!\n";
            return;
        } else {
            arr[rear] = element;
            rear = (rear + 1) % size; 
            cout << "Element: " << element << " pushed successfully\n";
        }
    }

    void pop() {
        if (isempty()) {
            cout << "No element available\n";
            return;
        } else {
            cout << "Element: " << arr[front] << " popped successfully\n";
            front = (front + 1) % size; 
        }
    }

    bool isfull() {
        return (rear + 1) % size == front; 
    }

    bool isempty() {
        return front == rear; 
    }

    void show_front() {
        if (isempty()) {
            cout << "No element in Queue!!!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        cout << "Queue elements: ";
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size; 
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
        cout << "Queue deleted successfully!!!\n";
    }
};

int main() {
    Queue firstQueue(5);

    // Test case 1: Push and pop elements normally
    firstQueue.push(2);
    firstQueue.push(3);
    firstQueue.push(4);
    firstQueue.push(5);
    firstQueue.display();

    // Test case 2: Pop an element
    firstQueue.pop();
    firstQueue.display();

    // Test case 3: Push when there is space
    firstQueue.push(6);
    firstQueue.display();

    // Test case 4: Push when the queue is full
    firstQueue.push(7); // This should fail since the queue is full
    firstQueue.display();

    // Test case 5: Pop all elements to empty the queue
    firstQueue.pop();
    firstQueue.pop();
    firstQueue.pop();
    firstQueue.display();

    // Test case 6: Show front when queue is empty
    firstQueue.show_front();

    // Test case 7: Push after popping elements
    firstQueue.push(8);
    firstQueue.display();
    firstQueue.push(9);
    firstQueue.display();

    return 0;
}
