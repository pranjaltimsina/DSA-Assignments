#include<iostream>

using namespace std;

// Create class BST for storing data
class BST {
public:
    // node to store individial elements
    struct node {
        int data;
        node* left;
        node* right;
    };

    // initialize the root of the BST
    node* root;

    // recursively remove a node
    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    // function to insert into the BST recursively
    node* insert(int x, node* t) {

        if(t == NULL) {

            // check if root
            t = new node;
            t->data = x;
            t->left = t->right = NULL;

        } else if(x < t->data)

            // insert in the left subtree if smaller
            t->left = insert(x, t->left);

        else if(x > t->data)

            // insert in the right subtree if greater
            t->right = insert(x, t->right);

        return t;
    }

    node* findMin(node* t) {
        // find the minimum element recursively
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            // if leftmost leaf then return the node
            return t;
        else

            // continue recursion
            return findMin(t->left);
    }

    node* findMax(node* t) {
        // find the maximum element recursively
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            // if right mostleaf then return the node
            return t;
        else
            // continue recursion
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        // search and remove a node with data x

        node* temp;
        if(t == NULL)

            // if empty tree, return null
            return NULL;
        else if(x < t->data)

            // if x is less than data in current node
            // find and remove from left sub tree
            t->left = remove(x, t->left);

        else if(x > t->data)

            // if x is more than data in current node
            // find and remove from right sub tree
            t->right = remove(x, t->right);
        else if(t->left && t->right) {
            // rearrage the tree
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        } else {

            // rearrage the tree
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        // inorder traversal of the tree
        if(t == NULL)
            return;
        // recurse for left node
        inorder(t->left);
        cout << t->data << " ";
        // recurse for right node
        inorder(t->right);
    }

    node* find(node* t, int x) {
        // recursively find node with int x
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    BST() {
        // default constructor
        root = NULL;
    }

    ~BST() {
        // destructor
        root = makeEmpty(root);
    }

    void insert(int x) {
        // insert into tree
        root = insert(x, root);
    }

    void remove(int x) {
        // remove fromm tree
        root = remove(x, root);
    }

    void display() {
        // display tree inorder
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        // search from tree
        root = find(root, x);
    }
};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    // t.display();
    // t.remove(20);
    // t.display();
    // t.remove(25);
    // t.display();
    // t.remove(30);
    // t.display();

    std::cout << t.findMin(t.root)->data;
    return 0;
}
