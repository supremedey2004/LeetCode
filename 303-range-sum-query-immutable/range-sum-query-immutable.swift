class NumArray {

    private var prefix: [Int]

    init(_ nums: [Int]) {
        prefix = Array(repeating: 0, count: nums.count + 1)

        for i in 0..<nums.count {
            prefix[i + 1] = prefix[i] + nums[i]
        }
    }

    func sumRange(_ left: Int, _ right: Int) -> Int {
        return prefix[right + 1] - prefix[left]
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * let ret_1: Int = obj.sumRange(left, right)
 */