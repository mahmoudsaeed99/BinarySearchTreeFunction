#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class BSTNode
{
public:
    int data;
    string d;
    BSTNode* left;
    BSTNode* right;
    vector<int>vec;

};
BSTNode* root;
class BSTFCI
{
public:
    BSTNode* newNode(BSTNode* crr,int data)
{
    if(crr==NULL){
        crr=new BSTNode();
        crr->data=data;
        return crr;
    }
    if(data < crr->data){
        crr->left=newNode(crr->left,data);
    }
    else if(data > crr->data){
        crr->right =newNode(crr->right,data);
    }
    return crr;

}
    int height(BSTNode* node)
    {
        /* base case tree is empty */
        if(node == NULL)
            return 0;

        /* If tree is not empty then
        height = 1 + max of left
            height and right heights */
        return 1 + max(height(node->left),
                       height(node->right));
    }
    bool isBalanced(BSTNode* crr)
    {
        int lh; /* for height of left subtree */
        int rh; /* for height of right subtree */

        /* If tree is empty then return true */
        if(crr == NULL)
            return 1;

        /* Get the height of left and right sub trees */
        lh = height(crr->left);
        rh = height(crr->right);

        if( abs(lh-rh) <= 1 &&  //function returns the absolute value
                isBalanced(crr->left) &&
                isBalanced(crr->right))
            return 1;

        /* If we reach here then
        tree is not height-balanced */
        return 0;
    }
    bool areIdentical(BSTNode * root1, BSTNode *root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    /* Check if the data of both roots is
    same and data of left and right
    subtrees are also same */
    return (root1->data == root2->data &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}
bool isSubtree(BSTNode *T, BSTNode *S)
{
    /* base cases */
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    /* Check the tree with root as current node */
    if (areIdentical(T, S))
        return true;

    /* If the tree with root as current
    node doesn't match then try left
    and right subtrees one by one */
    return isSubtree(T->left, S) ||
        isSubtree(T->right, S);
}
void print_range(BSTNode* crr,int key1,int key2){
  if (crr == NULL) return;
  if (crr->data <= key2) print_range( crr->right, key1, key2);
  if (crr->data >= key1 && crr->data <= key2) cout<<crr->data<<" ";
  if (crr->data >= key1) print_range( crr->left , key1, key2);

}
void inOrder(BSTNode* node)
{
    if (node == NULL)
        return;
    cout << node->data <<endl;
    inOrder(node->left);
    inOrder(node->right);
}
void flip(BSTNode* crr){
    if(crr==NULL){
        return;
    }
    else{
        BSTNode* new_node=new BSTNode();
        flip(crr->left);
        flip(crr->right);

        /* swap the pointers in this node */
        new_node = crr->left;
        crr->left = crr->right;
        crr->right = new_node;
    }

}
BSTNode* app_Node(BSTNode* crr , string data , int i)
{
            if(crr==NULL){
                crr=new BSTNode();
                crr->d=data;
                crr->vec.push_back(i);
                return crr;

            }
            if(data==crr->d){
                crr->vec.push_back(i);
                return crr;
            }
            else if(data < crr->d){
                crr->left=app_Node(crr->left,data,i);
            }
            else if(data > crr->d){
                crr->right =app_Node(crr->right,data,i);
            }
            return crr;

}
void print(BSTNode* crr){
    if(crr==NULL){
        return;
    }
         print(crr->right);
        cout<<crr->d<<"---";
        for(int i=0;i<crr->vec.size();i++){
            cout<<crr->vec[i]<<",";
        }
        cout<<endl;
         print(crr->left);

}
void application(){
    string x;
    int y;
    BSTNode* t=NULL;
    vector<string>v;
    cout<<" how many number of line that you want"<<endl;
    cin>>y;
    cout<<"write the text"<<endl;
    for(int i=0;i<=y;i++){
    getline(cin,x);
    istringstream buf(x);
    for(string word; buf >> word; )
        if(word==","||word=="."){

        }
        else{
          t=app_Node(t,word,i);
        }
    }
   print(t);

}
};
int main()
{
    BSTFCI b3;
    BSTNode* t=NULL;
    t=b3.newNode(t,26);
    t=b3.newNode(t,30);
    t=b3.newNode(t,15);
    t=b3.newNode(t,10);
    t=b3.newNode(t,12);
    t=b3.newNode(t,18);
    b3.inOrder(t);
    cout<<"-----------------------------------------"<<endl;
    cout<<b3.isBalanced(t)<<endl;
    b3.print_range(t,10,15);
    cout<<"-----------------------------------------"<<endl;
    b3.flip(t);
    b3.inOrder(t);
    cout<<"-----------------------------------------"<<endl;
    BSTFCI b,b1,b2;
    BSTNode* h,*s;
    s=b.newNode(s,26);
    s=b.newNode(s,30);
    s=b.newNode(s,15);
    cout<<b.isSubtree(t,s)<<endl;
    b.application();
    return 0;
}
