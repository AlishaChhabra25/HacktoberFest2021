// C++ program to calculate the range sum of BST nodes within a given range

#include<bits/stdc++.h>
using namespace std;
 
// A BST node
struct node
{    int val;
    struct node* left, *right;
};
// Utility function to create a new node
node *newNode(int val)
{
    node *temp = new node;
    temp->val  = val;
    temp->left  = temp->right = NULL;
    return (temp);
}

// Returns the sum of nodes in BST in the range [low, high]
int sum =0;
// Recursive function to traverse the nodes 
int rangeSumBST(node* root, int low, int high) 
    {
      // If the current node has null in its value, then return to the corresponding function call
      if(root == NULL) 
      {
          return sum;
      }
      // If the current node's value lies in the given range, then add its value to the sum variable.
      if(root->val>=low && root->val<=high)
      {
          sum += root->val;
          // Call its left subtree recursively
          rangeSumBST(root->left,low,high);
          // Call its right subtree recursively
          rangeSumBST(root->right,low,high);
      }
      // If the current node's value is less than the low, call its right subtree recursively.
      else if (root->val < low)
      {
        rangeSumBST(root->right,low,high);
      }
      // If the current node's value is greater than the high, call its left subtree recursively.
      else
      {
        rangeSumBST(root->left,low,high);
      }
    return sum;
    }
    
int main()
{
    /* Let us constructed BST shown in the above example-1
          10
        /    \
      5       15
     / \        \
    4   7        18   */
    
    node *root        = newNode(10);
    root->left        = newNode(5);
    root->right       = newNode(15);
    root->left->left  = newNode(4);
    root->left->right = newNode(7);
    root->right->right = newNode(100);
    
    int low, high;
    cout<<"Enter the starting value of the range: "<<endl;
    cin>>low;
    cout<<"Enter the ending value of the range: "<<endl;
    cin>>high;
    // function call
    cout << "Range sum of BST between [" << low << ", " << high
         << "] is " << rangeSumBST(root, low, high);
    return 0;
}
