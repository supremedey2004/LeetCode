impl Solution {
    pub fn min_wasted_space(mut packages: Vec<i32>, boxes: Vec<Vec<i32>>) -> i32 {
        const MOD: i64 = 1_000_000_007;

        packages.sort();

        let n = packages.len();

        let mut prefix = vec![0i64; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + packages[i] as i64;
        }

        let mut ans = i64::MAX;

        for mut supplier in boxes {
            supplier.sort();

            if *supplier.last().unwrap() < packages[n - 1] {
                continue;
            }

            let mut waste = 0i64;
            let mut idx = 0usize;

            for &b in &supplier {
                let next = upper_bound(&packages, idx, b);

                waste += (next - idx) as i64 * b as i64 - (prefix[next] - prefix[idx]);

                idx = next;
                if idx == n {
                    break;
                }
            }

            ans = ans.min(waste);
        }

        if ans == i64::MAX {
            -1
        } else {
            (ans % MOD) as i32
        }
    }
}

fn upper_bound(arr: &Vec<i32>, start: usize, target: i32) -> usize {
    let mut l = start;
    let mut r = arr.len();

    while l < r {
        let mid = (l + r) / 2;
        if arr[mid] <= target {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    l
}