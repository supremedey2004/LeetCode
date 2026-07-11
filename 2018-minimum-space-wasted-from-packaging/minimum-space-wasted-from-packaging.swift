class Solution {
    func minWastedSpace(_ packages: [Int], _ boxes: [[Int]]) -> Int {
        let MOD = 1_000_000_007

        let packages = packages.sorted()
        let n = packages.count

        var prefix = Array(repeating: Int64(0), count: n + 1)
        for i in 0..<n {
            prefix[i + 1] = prefix[i] + Int64(packages[i])
        }

        var ans = Int64.max

        for var supplier in boxes {
            supplier.sort()

            if supplier.last! < packages.last! {
                continue
            }

            var waste: Int64 = 0
            var idx = 0

            for b in supplier {
                let next = upperBound(packages, idx, b)

                waste += Int64(next - idx) * Int64(b) - (prefix[next] - prefix[idx])

                idx = next
                if idx == n {
                    break
                }
            }

            ans = min(ans, waste)
        }

        return ans == Int64.max ? -1 : Int(ans % Int64(MOD))
    }

    private func upperBound(_ arr: [Int], _ start: Int, _ target: Int) -> Int {
        var left = start
        var right = arr.count

        while left < right {
            let mid = (left + right) / 2
            if arr[mid] <= target {
                left = mid + 1
            } else {
                right = mid
            }
        }

        return left
    }
}