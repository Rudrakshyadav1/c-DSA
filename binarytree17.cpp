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
    cout << "Enter data to be inserted: ";
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
bool kthancestorHelper(int targetNode, int& k, node* root, int& ans) {
    if (root == nullptr) {
        return false; 
    }
    if (root->data == targetNode) {
        k--; 
        return true;
    }
    if (kthancestorHelper(targetNode, k, root->left, ans) || kthancestorHelper(targetNode, k, root->right, ans)){
        if (k == 0) {
            ans = root->data;
            return false; 
        }
        k--; 
        return true;
    }
    return false; 
}
void kthancestor(int targetNode, int& k, node* root, int& ans) {
    ans = -1; 
    bool found = kthancestorHelper(targetNode, k, root, ans);
    if (found && ans == -1){
        cout << "No ancestor found." << endl;
    }
}
int main() {
    node* root = nullptr;
    BinaryTreeConstructor(root); 
    cout << "Enter the value of the node: ";
    int nodeVal;
    cin >> nodeVal;
    cout << "\n";
    cout << "Enter the value of k: ";
    int k;
    cin >> k;
    cout << "\n";
    int ans;
    kthancestor(nodeVal, k, root, ans);
    if (ans >= 0) {
        cout << "The ancestor is " << ans << endl;
    } else {
        cout << "No ancestor found" << endl;
    }
    return 0;
}
