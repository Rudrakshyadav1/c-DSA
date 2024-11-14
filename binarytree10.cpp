#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
node* BuildBinaryTree() {
    int data;
    cout << "Enter data to be inserted (or -1 to stop): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }
    node* newNode = new node(data);
    cout << "Inserting elements to the left of " << data << ":\n";
    newNode->left = BuildBinaryTree();
    cout << "Inserting elements to the right of " << data << ":\n";
    newNode->right = BuildBinaryTree();
    return newNode;
}
void traversalLeft(node* root, vector<int>& ans){
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }
    ans.push_back(root->data); 
    if (root->left != nullptr) {
        traversalLeft(root->left, ans); 
    } else {
        traversalLeft(root->right, ans); 
    }
} 
void traversalLeaf(node* root, vector<int>& ans) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(root->data); 
    }
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}
void traversalRight(node* root, vector<int>& ans) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return;
    }
    if (root->right != nullptr) {
        traversalRight(root->right, ans);
    } else {
        traversalRight(root->left, ans); 
    }
    ans.push_back(root->data); 
}
vector<int> BoundryTraversal(node* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans; 
    }
    ans.push_back(root->data); 
    traversalLeft(root->left, ans);
    traversalLeaf(root->left, ans); 
    traversalLeaf(root->right, ans); 
    traversalRight(root->right, ans);

    return ans;
}
int main() {
    node* root = BuildBinaryTree();
    vector<int> ans = BoundryTraversal(root);
    
    cout << "Boundary elements: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
