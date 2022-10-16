#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int height(node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    int rHeight=height(root->right);
    int lHeight=height(root->left);
    return max(rHeight,lHeight)+1;
}

int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int rHeight=height(root->right);
    int lHeight=height(root->left);
    int currDiameter=rHeight+lHeight+1;
    int lDiameter=diameter(root->left);
    int rDiameter=diameter(root->right);
    
    return max(currDiameter,max(rDiameter,lDiameter));
}

int calcDiameter(node* root,int* height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter=calcDiameter(root->left,&lh);
    int rDiameter=calcDiameter(root->right,&rh);

    int currentDiameter=lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currentDiameter,max(lDiameter,rDiameter));

}

int main()
{
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(5);
    root->left->left=new node(4);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int Height=0;
    cout<<"Height of the tree is= "<<height(root)<<endl;
    cout<<"Diameter of the tree is= "<<calcDiameter(root,&Height)<<endl;

    return 0;
}