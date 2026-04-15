#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

// Insert
struct Node* insert(struct Node* r, int x) {
    if (!r) return newNode(x);
    if (x < r->data) r->left = insert(r->left, x);
    else r->right = insert(r->right, x);
    return r;
}

// Search
void search(struct Node* r, int x) {
    if (!r) printf("Not Found\n");
    else if (r->data == x) printf("Found\n");
    else if (x < r->data) search(r->left, x);
    else search(r->right, x);
}

// Inorder
void inorder(struct Node* r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

// Main menu
int main() {
    struct Node* root = NULL;
    int ch, x;

    while (1) {
        printf("\n1.Insert 2.Search 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                scanf("%d", &x);
                search(root, x);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                return 0;
        }
    }
}
