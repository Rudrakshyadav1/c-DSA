#include <iostream>
#include <climits> 
using namespace std;
class node{
public:
    node* left;
    node* right;
    int data;
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
void BinaryTreeConstructor(node*& root){
    int n;
    cout << "Enter data to be inserted : ";
    cin >> n;
    cout << "\n";
    if (n == -1){
        return;
    }
    root = new node(n);
    cout << "Enter data for the left node of " << n << "\n";
    BinaryTreeConstructor(root->left);
    cout << "\n";
    cout << "Enter data for the right node of " << n << "\n";
    BinaryTreeConstructor(root->right);
    cout << "\n";
}
void solver(int len, int sum, int& maxlen, int& maxsum, node* root){
    if (root == nullptr) {
        if(len > maxlen){
            maxlen = len;
            maxsum = sum;
        }
        else if(len == maxlen && sum > maxsum){
            maxsum = sum;
        }
        return;
    }
    solver(len + 1, sum + root->data, maxlen, maxsum, root->left);
    solver(len + 1, sum + root->data, maxlen, maxsum, root->right);
}

void SumOfLongest(node* root){
    int maxlen = 0;
    int maxsum = INT_MIN;
    solver(0, 0, maxlen, maxsum, root);
    cout << "Max Length of path: " << maxlen << endl;
    cout << "Max Sum of path: " << maxsum << endl;
}
int main(){
    node* root = nullptr;
    BinaryTreeConstructor(root);
    SumOfLongest(root);
    return 0;
}
