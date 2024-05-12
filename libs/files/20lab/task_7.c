#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }

    int maxIndex = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }

    struct TreeNode *root = newNode(nums[maxIndex]);

    root->left = constructMaximumBinaryTree(nums, maxIndex);

    root->right = constructMaximumBinaryTree(nums + maxIndex + 1, numsSize - maxIndex - 1);

    return root;
}

void printLevelOrder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode *node = queue[front++];
        if (node != NULL) {
            printf("%d ", node->val);
            queue[rear++] = node->left;
            queue[rear++] = node->right;
        }
    }
}

void testConstructMaximumBinaryTree() {
    int nums[] = {3, 2, 1, 6, 0, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    struct TreeNode *result = constructMaximumBinaryTree(nums, numsSize);
    printf("Input: [3,2,1,6,0,5]\nOutput: ");
    printLevelOrder(result);
}

int main() {
    testConstructMaximumBinaryTree();
    return 0;
}