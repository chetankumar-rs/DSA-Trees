#include<iostream>
using namespace std;

struct NODE
{
    int data;
    NODE* left;
    NODE* right;

    NODE(int value)
    {   
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(NODE* value){
    if(value == nullptr)
        return;
    else{
            cout<<value->data<<" ";
            preorder(value->left);
            preorder(value->right);
        }
}

int main(){
    NODE* root = new NODE(1);
    root->left = new NODE(2);
    root->right = new NODE(3);
    root->left->left = new NODE(4);
    root->left->right  = new NODE(5);
    root->right->left = new NODE(6);
    root->right->right = new NODE(7);

    cout<<"Preorder Traversal: ";
    preorder(root);
    return 0;
    
}