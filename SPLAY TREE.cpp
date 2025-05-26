#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the splay tree
struct node {
    int key;
    struct node *left, *right;
};

// Function to create a new node with a given key
struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rotate utility function
struct node* rightRotate(struct node* x) {
    struct node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotate utility function
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay function to bring the key to the root
struct node* splay(struct node* root, int key) {
    // Base cases
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (root->key > key) {
        // Key is not in tree, we are done
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);

            // Do first rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (root->left->key < key) {
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);

            // Do second rotation for root
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Do first rotation for root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key lies in right subtree
    else {
        // Key is not in tree, we are done
        if (root->right == NULL)
            return root;

        // Zig-Zag (Right Left)
        if (root->right->key > key) {
            // First recursively bring the key as root of right-left
            root->right->left = splay(root->right->left, key);

            // Do second rotation for root
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zig-Zig (Right Right)
        else if (root->right->key < key) {
            // First recursively bring the key as root of right-right
            root->right->right = splay(root->right->right, key);

            // Do first rotation for root
            root = leftRotate(root);
        }

        // Do first rotation for root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Function to search a key in the splay tree
struct node* search(struct node* root, int key) {
    return splay(root, key);
}

// Preorder traversal of the splay tree
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Main function to demonstrate the splay tree operations
int main() {
    struct node* root = newNode(100);
    root->left = newNode(50);
    root->right = newNode(200);
    root->left->left = newNode(40);
    root->left->left->left = newNode(30);
    root->left->left->left->left = newNode(20);

    printf("Preorder traversal before splaying:\n");
    preOrder(root);
    printf("\n");

    root = search(root, 20);

    printf("Preorder traversal after splaying:\n");
    preOrder(root);
    printf("\n");

    return 0;
}

