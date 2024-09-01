#include<iostream>
using namespace std;

class node{

    public : 
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node * insertinbst(node *root,int d)
{
    if( !root )
    {
        root = new node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = insertinbst(root->right,d);
    }
    else
    root->left = insertinbst(root->left,d);

    return root;

}
void takeinput(node *&root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        insertinbst(root,data);
        cin >> data;
    }
}
int main()
{
    node *root = NULL;

    cout<<"Enter data to BST : ";
    takeinput(root);
    cout<<"Printing the BST \n";
    
    return 0;
}