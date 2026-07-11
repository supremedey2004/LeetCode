import (
	"math"
	"sort"
)

func minWastedSpace(packages []int, boxes [][]int) int {
	const MOD int64 = 1_000_000_007

	sort.Ints(packages)

	n := len(packages)

	prefix := make([]int64, n+1)
	for i := 0; i < n; i++ {
		prefix[i+1] = prefix[i] + int64(packages[i])
	}

	ans := int64(math.MaxInt64)

	for _, supplier := range boxes {
		sort.Ints(supplier)

		if supplier[len(supplier)-1] < packages[n-1] {
			continue
		}

		var waste int64
		idx := 0

		for _, b := range supplier {
			next := sort.Search(len(packages)-idx, func(i int) bool {
				return packages[idx+i] > b
			}) + idx

			waste += int64(next-idx)*int64(b) - (prefix[next] - prefix[idx])

			idx = next
			if idx == n {
				break
			}
		}

		if waste < ans {
			ans = waste
		}
	}

	if ans == int64(math.MaxInt64) {
		return -1
	}

	return int(ans % MOD)
}