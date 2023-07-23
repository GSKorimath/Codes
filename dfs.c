#include <stdio.h>
#include <stdlib.h>

// Structure for the tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to construct the binary tree from input file
TreeNode* constructTree(FILE* inputFile) {
    int data;
    fscanf(inputFile, "%d", &data);

    if (data == -1) {
        return NULL;
    }

    TreeNode* root = createNode(data);
    root->left = constructTree(inputFile);
    root->right = constructTree(inputFile);

    return root;
}

// Function to perform Depth-First Search (DFS) Inorder traversal and write to output file
void dfsInorder(TreeNode* root, FILE* outputFile) {
    if (root == NULL)
        return;

    dfsInorder(root->left, outputFile);
    fprintf(outputFile, "%d ", root->data);
    dfsInorder(root->right, outputFile);
}

// Function to perform Depth-First Search (DFS) Preorder traversal and write to output file
void dfsPreorder(TreeNode* root, FILE* outputFile) {
    if (root == NULL)
        return;

    fprintf(outputFile, "%d ", root->data);
    dfsPreorder(root->left, outputFile);
    dfsPreorder(root->right, outputFile);
}

// Function to perform Depth-First Search (DFS) Postorder traversal and write to output file
void dfsPostorder(TreeNode* root, FILE* outputFile) {
    if (root == NULL)
        return;

    dfsPostorder(root->left, outputFile);
    dfsPostorder(root->right, outputFile);
    fprintf(outputFile, "%d ", root->data);
}

int main() {
    // Read the binary tree from input file
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    TreeNode* root = constructTree(inputFile);
    fclose(inputFile);

    // Perform DFS traversals and store the results in the output file
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(outputFile, "Inorder traversal: ");
    dfsInorder(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Preorder traversal: ");
    dfsPreorder(root, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Postorder traversal: ");
    dfsPostorder(root, outputFile);
    fprintf(outputFile, "\n");

    fclose(outputFile);
    printf("DFS traversals are completed and stored in output.txt.\n");

    return 0;
}

