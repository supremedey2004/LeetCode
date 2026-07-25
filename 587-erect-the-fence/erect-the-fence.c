#include <stdlib.h>

int cross(int *o, int *a, int *b) {
    return (a[0] - o[0]) * (b[1] - o[1]) -
           (a[1] - o[1]) * (b[0] - o[0]);
}

int cmp(const void *a, const void *b) {
    int *p = *(int **)a;
    int *q = *(int **)b;

    if (p[0] == q[0])
        return p[1] - q[1];
    return p[0] - q[0];
}

int** outerTrees(int** trees, int treesSize, int* treesColSize,
                 int* returnSize, int** returnColumnSizes) {

    if (treesSize <= 1) {
        *returnSize = treesSize;
        *returnColumnSizes = (int *)malloc(sizeof(int) * treesSize);
        for (int i = 0; i < treesSize; i++)
            (*returnColumnSizes)[i] = 2;
        return trees;
    }

    qsort(trees, treesSize, sizeof(int *), cmp);

    int **hull = (int **)malloc(sizeof(int *) * (2 * treesSize));
    int k = 0;

    // Lower hull
    for (int i = 0; i < treesSize; i++) {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], trees[i]) < 0)
            k--;
        hull[k++] = trees[i];
    }

    // Upper hull
    int t = k + 1;
    for (int i = treesSize - 2; i >= 0; i--) {
        while (k >= t && cross(hull[k - 2], hull[k - 1], trees[i]) < 0)
            k--;
        hull[k++] = trees[i];
    }

    // Remove duplicates
    int **ans = (int **)malloc(sizeof(int *) * treesSize);
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        int found = 0;
        for (int j = 0; j < cnt; j++) {
            if (ans[j][0] == hull[i][0] && ans[j][1] == hull[i][1]) {
                found = 1;
                break;
            }
        }
        if (!found)
            ans[cnt++] = hull[i];
    }

    *returnSize = cnt;
    *returnColumnSizes = (int *)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++)
        (*returnColumnSizes)[i] = 2;

    free(hull);
    return ans;
}