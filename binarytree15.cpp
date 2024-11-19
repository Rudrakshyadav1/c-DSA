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
node* Lowestcommonancestor(node* root, int n, int p) {
    if (root == nullptr) {
        return nullptr;
    }
    if(root->data == n || root->data == p) {
        return root;
    }
    node* leftLCA = Lowestcommonancestor(root->left, n, p);
    node* rightLCA = Lowestcommonancestor(root->right, n, p);
    if (leftLCA && rightLCA){
        return root;
    }
    return(leftLCA !=nullptr)?leftLCA:rightLCA;
}
int main(){
    node*root;
    root=nullptr;
    BinaryTreeConstructor(root);
    int n;
    int p;
    cout<<"Enter data for first ancestor:";
    cin>>n;
    cout<<"\n";
    cout<<"Enter data for second ancestor:";
    cin>>p;
    Lowestcommonancestor(root,n,p);


}