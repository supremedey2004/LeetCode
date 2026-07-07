class Solution {
    func maxCount(_ m: Int, _ n: Int, _ ops: [[Int]]) -> Int {
        var minRow = m
        var minCol = n

        for op in ops {
            minRow = min(minRow, op[0])
            minCol = min(minCol, op[1])
        }

        return minRow * minCol
    }
}