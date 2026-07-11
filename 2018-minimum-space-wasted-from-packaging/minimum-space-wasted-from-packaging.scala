object Solution {
    def minWastedSpace(packages: Array[Int], boxes: Array[Array[Int]]): Int = {
        val MOD = 1000000007L

        scala.util.Sorting.quickSort(packages)

        val n = packages.length

        val prefix = new Array[Long](n + 1)
        for (i <- 0 until n)
            prefix(i + 1) = prefix(i) + packages(i)

        var ans = Long.MaxValue

        for (supplier <- boxes) {
            scala.util.Sorting.quickSort(supplier)

            if (supplier.last >= packages.last) {
                var waste = 0L
                var idx = 0

                for (b <- supplier if idx < n) {
                    val next = upperBound(packages, idx, b)

                    waste += (next - idx).toLong * b - (prefix(next) - prefix(idx))

                    idx = next
                }

                ans = math.min(ans, waste)
            }
        }

        if (ans == Long.MaxValue) -1
        else (ans % MOD).toInt
    }

    def upperBound(arr: Array[Int], start: Int, target: Int): Int = {
        var l = start
        var r = arr.length

        while (l < r) {
            val mid = (l + r) / 2
            if (arr(mid) <= target)
                l = mid + 1
            else
                r = mid
        }

        l
    }
}