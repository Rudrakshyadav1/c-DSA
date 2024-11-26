#include <iostream>
using namespace std;

class node {
public:
    node* left;
    node* right;
    int data;
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

void BinaryTreeConstructor(node*& root) {
    int n;
    cout << "Enter data to be inserted (-1 to stop): ";
    cin >> n;
    if (n == -1) {
        return;
    }
    root = new node(n);
    cout << "Enter data for the left node of " << n << "\n";
    BinaryTreeConstructor(root->left);
    cout << "Enter data for the right node of " << n << "\n";
    BinaryTreeConstructor(root->right);
}
pair<int, int> maxNonAdjacentSum(node* root) {
    if (root == nullptr) {
        return {0, 0}; 
    }
 pair<int, int> left = maxNonAdjacentSum(root->left);
pair<int, int> right = maxNonAdjacentSum(root->right);
    int include = root->data + left.second + right.second;
    int exclude = max(left.first, left.second) + max(right.first, right.second); 
    return {include, exclude};
}
int main() {
    node* root = nullptr;
    BinaryTreeConstructor(root);
    pair<int, int> result = maxNonAdjacentSum(root);
    cout << "The maximum sum of non-adjacent nodes is: " << max(result.first,result.second) << endl;
    return 0;
}