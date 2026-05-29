#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 200003

typedef struct Node {
    int key;
    int index;
    struct Node* next;
} Node;

int hash(int key) {
    long long x = key;
    if (x < 0) x = -x;
    return x % SIZE;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    Node* hashTable[SIZE] = {NULL};   // local table, automatically fresh

    for (int i = 0; i < numsSize; i++) {
        int h = hash(nums[i]);
        Node* curr = hashTable[h];

        while (curr != NULL) {
            if (curr->key == nums[i]) {
                if (i - curr->index <= k) {
                    return true;
                }

                curr->index = i;  // update latest index
                break;
            }
            curr = curr->next;
        }

        if (curr == NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->key = nums[i];
            newNode->index = i;
            newNode->next = hashTable[h];
            hashTable[h] = newNode;
        }
    }

    return false;
}