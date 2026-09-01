import java.util.*;

class Solution {

    static class State {
        int row;
        int col;
        int mask;
        int remainingEnergy;

        State(int row, int col, int mask, int remainingEnergy) {
            this.row = row;
            this.col = col;
            this.mask = mask;
            this.remainingEnergy = remainingEnergy;
        }
    }

    public int minMoves(String[] classroom, int energy) {

        int m = classroom.length;
        int n = classroom[0].length();

        int startRow = 0;
        int startCol = 0;

        int[][] litterIndex = new int[m][n];

        for (int i = 0; i < m; i++) {
            Arrays.fill(litterIndex[i], -1);
        }

        int litterCount = 0;

        // Find starting position and litter positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                char cell = classroom[i].charAt(j);

                if (cell == 'S') {
                    startRow = i;
                    startCol = j;
                }

                if (cell == 'L') {
                    litterIndex[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0) {
            return 0;
        }

        int fullMask = (1 << litterCount) - 1;

        // best[row][col][mask] =
        // maximum remaining energy reached at this state
        int[][][] best = new int[m][n][1 << litterCount];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(best[i][j], -1);
            }
        }

        Queue<State> queue = new LinkedList<>();

        queue.offer(new State(startRow, startCol, 0, energy));

        best[startRow][startCol][0] = energy;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        int moves = 0;

        while (!queue.isEmpty()) {

            int size = queue.size();

            while (size-- > 0) {

                State curr = queue.poll();

                // All litter collected
                if (curr.mask == fullMask) {
                    return moves;
                }

                // Cannot move if energy is 0
                if (curr.remainingEnergy == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {

                    int newRow = curr.row + dr[d];
                    int newCol = curr.col + dc[d];

                    // Check boundaries
                    if (newRow < 0 || newRow >= m ||
                        newCol < 0 || newCol >= n) {
                        continue;
                    }

                    char cell = classroom[newRow].charAt(newCol);

                    // Cannot pass obstacle
                    if (cell == 'X') {
                        continue;
                    }

                    int newEnergy = curr.remainingEnergy - 1;
                    int newMask = curr.mask;

                    // Collect litter
                    if (cell == 'L') {
                        int index = litterIndex[newRow][newCol];
                        newMask |= (1 << index);
                    }

                    // Reset energy
                    if (cell == 'R') {
                        newEnergy = energy;
                    }

                    // Skip worse state
                    if (best[newRow][newCol][newMask] >= newEnergy) {
                        continue;
                    }

                    best[newRow][newCol][newMask] = newEnergy;

                    queue.offer(
                        new State(newRow, newCol, newMask, newEnergy)
                    );
                }
            }

            moves++;
        }

        return -1;
    }
}