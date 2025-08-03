#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
int val;
struct TreeNode* left;
struct TreeNode* right;
}TreeNode;

TreeNode* CriaNo(int valor) {
 TreeNode* tree = malloc(sizeof(TreeNode));
 tree -> val = valor;
 tree -> left = NULL;
 tree -> right = NULL;
 return tree;
}

int IsBalanced (TreeNode* root) {
int countleft,countright;
if (root -> left != NULL)
countleft++;
if (root -> right != NULL)
countright++;
if (countleft - 1 > countright)
return 1;
if (countright - 1 > countleft)
return 2;
return 0;
}

TreeNode* balanceBST(TreeNode* root) {
    if (IsBalanced(root) == 0)
    return root;
    else if (IsBalanced(root) == 1) { //esquerda desbalanceada

    } else if (IsBalanced(root) == 2) { //direita desbalanceada


    }

}

int main() {
TreeNode* tree;
tree = CriaNo(8);
tree -> left = CriaNo(6);
tree -> right = CriaNo(5);

}