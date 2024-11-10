#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
node* BuiltBinaryTree(node* root){
    int data;
    cout << "Enter data to be inserted (or -1 to stop): ";
    cin >> data;   
    if (data == -1) {
        return nullptr;  
    }
    root = new node(data);  
    cout << "Inserting elements to the left of " << data << ":\n";
    root->left = BuiltBinaryTree(root->left); 
    cout << "Inserting elements to the right of " << data << ":\n";
    root->right = BuiltBinaryTree(root->right);    return root; 
}
void levelOrderTraversal(node* root){
    if (root == nullptr) {
        return;  
    }
    queue<node*> q; 
    q.push(root);  
    while (!q.empty()){
        int levelSize = q.size(); 
        while (levelSize > 0){
            node* current = q.front();  
            q.pop(); 

            cout << current->data << " ";

            if (current->left != nullptr){
                q.push(current->left);
            }
            if (current->right != nullptr){
                q.push(current->right);
            }

            levelSize--; 
        }
        cout << endl;
    }
}

int main(){
    node* root = nullptr;
    root = BuiltBinaryTree(root);
    levelOrderTraversal(root);
}