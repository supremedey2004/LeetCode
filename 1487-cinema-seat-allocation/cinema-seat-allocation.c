#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int mask;
} Row;

/* Compare rows for qsort */
int compare(const void *a, const void *b) {
    Row *x = (Row *)a;
    Row *y = (Row *)b;

    return x->row - y->row;
}

int maxNumberOfFamilies(int n, int **reservedSeats, int reservedSeatsSize,
                        int *reservedSeatsColSize) {

    Row *rows = (Row *)malloc(reservedSeatsSize * sizeof(Row));

    int count = 0;

    /* Create a bitmask for each row */
    for (int i = 0; i < reservedSeatsSize; i++) {
        int row = reservedSeats[i][0];
        int seat = reservedSeats[i][1];

        rows[count].row = row;
        rows[count].mask = 1 << seat;
        count++;
    }

    /* Sort by row */
    qsort(rows, count, sizeof(Row), compare);

    long long ans = 2LL * n;

    int i = 0;

    while (i < count) {

        int row = rows[i].row;
        int mask = 0;

        /* Combine all reserved seats of the same row */
        while (i < count && rows[i].row == row) {
            mask |= rows[i].mask;
            i++;
        }

        /*
           Seat blocks:

           Left   : 2 3 4 5
           Middle : 4 5 6 7
           Right  : 6 7 8 9
        */

        int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        int left = (mask & leftMask) == 0;
        int middle = (mask & middleMask) == 0;
        int right = (mask & rightMask) == 0;

        /* This row was initially counted as 2 */
        ans -= 2;

        if (left && right)
            ans += 2;
        else if (left || middle || right)
            ans += 1;
    }

    free(rows);

    return (int)ans;
}