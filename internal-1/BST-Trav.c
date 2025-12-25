#include <stdio.h>
#include <stdlib.h>

struct btnode {
  int value;
  struct btnode *l;
  struct btnode *r;
};

struct btnode *root = NULL;

void insert();
struct btnode *createNode(int data);
void insertNode(struct btnode *t, struct btnode *temp);
void inorder(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);

void main() {
  int ch;

  printf("\nBINARY SEARCH TREE - TRAVERSALS ONLY");
  printf("\n1 - Insert an element");
  printf("\n2 - Inorder Traversal");
  printf("\n3 - Preorder Traversal");
  printf("\n4 - Postorder Traversal");
  printf("\n5 - Exit");

  while (1) {
    printf("\n\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      insert();
      break;
    case 2:
      if (root == NULL)
        printf("Tree is empty");
      else
        inorder(root);
      break;
    case 3:
      if (root == NULL)
        printf("Tree is empty");
      else
        preorder(root);
      break;
    case 4:
      if (root == NULL)
        printf("Tree is empty");
      else
        postorder(root);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice");
    }
  }
}

/* Insert function */
void insert() {
  int data;
  printf("Enter data to insert: ");
  scanf("%d", &data);

  struct btnode *temp = createNode(data);

  if (root == NULL)
    root = temp;
  else
    insertNode(root, temp);
}

/* Create new node */
struct btnode *createNode(int data) {
  struct btnode *temp;
  temp = (struct btnode *)malloc(sizeof(struct btnode));
  temp->value = data;
  temp->l = temp->r = NULL;
  return temp;
}

/* Recursive BST insert */
void insertNode(struct btnode *t, struct btnode *temp) {
  if (temp->value < t->value) {
    if (t->l == NULL)
      t->l = temp;
    else
      insertNode(t->l, temp);
  } else {
    if (t->r == NULL)
      t->r = temp;
    else
      insertNode(t->r, temp);
  }
}

/* Inorder Traversal */
void inorder(struct btnode *t) {
  if (t != NULL) {
    inorder(t->l);
    printf("%d -> ", t->value);
    inorder(t->r);
  }
}

/* Preorder Traversal */
void preorder(struct btnode *t) {
  if (t != NULL) {
    printf("%d -> ", t->value);
    preorder(t->l);
    preorder(t->r);
  }
}

/* Postorder Traversal */
void postorder(struct btnode *t) {
  if (t != NULL) {
    postorder(t->l);
    postorder(t->r);
    printf("%d -> ", t->value);
  }
}
