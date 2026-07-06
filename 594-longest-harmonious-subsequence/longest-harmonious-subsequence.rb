# @param {Integer[]} nums
# @return {Integer}
def find_lhs(nums)
  freq = Hash.new(0)

  nums.each do |num|
    freq[num] += 1
  end

  ans = 0

  freq.each do |key, value|
    if freq.key?(key + 1)
      ans = [ans, value + freq[key + 1]].max
    end
  end

  ans
end