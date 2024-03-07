#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int balance_factor;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

int get_balance_factor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* rotate_right(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->balance_factor = get_balance_factor(y);
    x->balance_factor = get_balance_factor(x);

    return x;
}

Node* rotate_left(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->balance_factor = get_balance_factor(x);
    y->balance_factor = get_balance_factor(y);

    return y;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->balance_factor = 0;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // Duplicates are not allowed
    }

    node->balance_factor = get_balance_factor(node);

    if (node->balance_factor > 1 && data < node->left->data) {
        return rotate_right(node);
    }

    if (node->balance_factor < -1 && data > node->right->data) {
        return rotate_left(node);
    }

    if (node->balance_factor > 1 && data > node->left->data) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (node->balance_factor < -1 && data < node->right->data) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

Node* find_min(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL) {
        return node;
    }
    return find_min(node->left);
}

Node* remove_node(Node* node, int data) {
    if (node == NULL) {
        return node;
    }

    if (data < node->data) {
        node->left = remove_node(node->left, data);
    } else if (data > node->data) {
        node->right = remove_node(node->right, data);
    } else {
        if (node->left == NULL || node->right == NULL) {
            Node* temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                temp = node;
                node = NULL;
            } else {
                *node = *temp;
            }

            free(temp);
        } else {
            Node* temp = find_min(node->right);
            node->data = temp->data;
            node->right = remove_node(node->right, temp->data);
        }
    }

    if (node == NULL) {
        return node;
    }

    node->balance_factor = get_balance_factor(node);

    if (node->balance_factor > 1 && get_balance_factor(node->left) >= 0) {
        return rotate_right(node);
    }

    if (node->balance_factor < -1 && get_balance_factor(node->right) <= 0) {
        return rotate_left(node);
    }

    if (node->balance_factor > 1 && get_balance_factor(node->left) < 0) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (node->balance_factor < -1 && get_balance_factor(node->right) > 0) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void inorder_traversal(Node* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the AVL tree: ");
    inorder_traversal(root);
    printf("\n");

    root = remove_node(root, 30);

    printf("Inorder traversal after removing 30: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}