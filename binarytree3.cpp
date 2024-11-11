#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class node     {
public:
    int data;
    node* left;
    node* right;

    node(int data){
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
    root->right = BuiltBinaryTree(root->right); 
    return root; 
}
//inorder LNR;
//preorder NLR;
//postorder LRN;
void allTraversal(node* root){ 
    vector<int> pre, in, post;  
    stack<pair<node*, int> > s; 
    s.push(make_pair(root, 1));  
    while (!s.empty()){
        pair<node*, int> p = s.top();   
        if (p.second == 1){
            s.top().second++;  
            pre.push_back(p.first->data);
            if (p.first->left !=nullptr) {
                s.push(make_pair(p.first->left, 1));  
            }
        }
        else if (p.second == 2){
            s.top().second++; 
            in.push_back(p.first->data);  
            if (p.first->right) {
                s.push(make_pair(p.first->right, 1)); 
            }
        }
        else{
            post.push_back(p.first->data);  
            s.pop();
        }
    }
    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++){
        cout << pre[i] << " ";
    }
    cout << "\n";

    cout << "Inorder Traversal: ";
    for (int i = 0; i < in.size(); i++){
        cout << in[i] << " ";
    }
    cout << "\n";

    cout << "Postorder Traversal: ";
    for (int i = 0; i < post.size(); i++){
        cout << post[i] << " ";
    }
    cout << "\n";
}
int main(){
    node* root = nullptr;
    root = BuiltBinaryTree(root);
    allTraversal(root);

}