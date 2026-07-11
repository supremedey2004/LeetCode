def min_wasted_space(packages, boxes)
  mod = 1_000_000_007

  packages.sort!

  n = packages.length

  prefix = Array.new(n + 1, 0)
  (0...n).each do |i|
    prefix[i + 1] = prefix[i] + packages[i]
  end

  ans = Float::INFINITY

  boxes.each do |supplier|
    supplier.sort!

    next if supplier[-1] < packages[-1]

    waste = 0
    idx = 0

    supplier.each do |b|
      nxt = upper_bound(packages, idx, b)

      waste += (nxt - idx) * b - (prefix[nxt] - prefix[idx])

      idx = nxt
      break if idx == n
    end

    ans = [ans, waste].min
  end

  ans == Float::INFINITY ? -1 : ans % mod
end

def upper_bound(arr, start, target)
  l = start
  r = arr.length

  while l < r
    mid = (l + r) / 2
    if arr[mid] <= target
      l = mid + 1
    else
      r = mid
    end
  end

  l
end