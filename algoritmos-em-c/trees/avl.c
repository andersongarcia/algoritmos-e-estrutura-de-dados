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
    return height(node->right) - height(node->left);
}

Node* rotate_right(Node* root) {
    Node* l = root->left;
    Node* r = l->right;

    l->right = root;
    root->left = r;

    root->balance_factor = get_balance_factor(root);
    l->balance_factor = get_balance_factor(l);

    return l;
}

Node* rotate_left(Node* root) {
    Node* r = root->right;
    Node* l = r->left;

    r->left = root;
    root->right = l;

    root->balance_factor = get_balance_factor(root);
    r->balance_factor = get_balance_factor(r);

    return r;
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

    if (node->balance_factor < -1){
        Node *l = node->left;
        if (l->balance_factor < 0) {
            rotate_right(node);
        }else{
            node->left = rotate_left(l);
            rotate_right(node);
        }
    }

    if (node->balance_factor > 1){
        Node *r = node->right;
        if (r->balance_factor > 0) {
            rotate_left(node);
        }else{
            node->right = rotate_right(r);
            rotate_left(node);
        }
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