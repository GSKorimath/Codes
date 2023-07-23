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

// Function to perform Breadth-First Search (BFS) traversal and write to output file
void bfs(TreeNode* root, FILE* outputFile) {
    if (root == NULL)
        return;

    // Create a queue for BFS
    TreeNode* queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue the front node and print its data
        TreeNode* currentNode = queue[front++];
        fprintf(outputFile, "%d ", currentNode->data);

        // Enqueue the left child
        if (currentNode->left != NULL)
            queue[rear++] = currentNode->left;

        // Enqueue the right child
        if (currentNode->right != NULL)
            queue[rear++] = currentNode->right;
    }
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

    // Perform BFS traversal and store the result in the output file
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(outputFile, "BFS traversal: ");
    bfs(root, outputFile);
    fprintf(outputFile, "\n");

    fclose(outputFile);
    printf("BFS traversal is completed and stored in output.txt.\n");

    return 0;
}
