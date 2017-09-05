#include<iostream>
using namespace std;

//Data structure node to hold node of a tree
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//Allocate memory for tree node
struct node* createNode(int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return(newNode);
}

/*return true if both tree a and b have same structure
else return false  
*/
bool sameStructureTree(struct node* a, struct node* b)
{
    //if both tree are empty
    if (a==NULL && b==NULL)
        return true;

    //compare both non-empty tree recursively
   if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            sameStructureTree(a->left, b->left) &&
            sameStructureTree(a->right, b->right)
        );
    }
   
    //if one tree is empty and other is not return false
    return false;
}

int main()
{
    struct node *s = createNode(1);
    struct node *t = createNode(1);
    s->left = createNode(2);
    s->right = createNode(3);
    s->left->left = createNode(4);
    s->left->right = createNode(5);

    t->left = createNode(2);
    t->right = createNode(3);
    t->left->left = createNode(4);
    t->left->right = createNode(5);

    if(sameStructureTree(s, t))
        cout<<"Both tree have same Structure.";
    else
        cout<<"Both tree have different Structure";

  
return 0;
}

/*OUTPUT:

Both tree have same Structure.

Expalination:

Time complexity of above problem depends on the number of nodes in the tree as we are traversing the tree.
suppose tree1 has m node and tree2 has n node
if (m==n) time complexity is O(m) or O(n)
if(m<n)   time complexity is O(m)
else      time complexity is O(n)*/
