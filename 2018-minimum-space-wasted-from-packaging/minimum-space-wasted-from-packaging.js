var minWastedSpace = function(packages, boxes) {
    const MOD = 1000000007n;

    packages.sort((a, b) => a - b);

    const n = packages.length;

    const prefix = Array(n + 1).fill(0n);

    for (let i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + BigInt(packages[i]);

    let ans = null;

    function upperBound(arr, start, target) {
        let l = start, r = arr.length;

        while (l < r) {
            let mid = (l + r) >> 1;
            if (arr[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    for (let supplier of boxes) {
        supplier.sort((a, b) => a - b);

        if (supplier[supplier.length - 1] < packages[n - 1])
            continue;

        let waste = 0n;
        let idx = 0;

        for (let b of supplier) {
            let nxt = upperBound(packages, idx, b);

            waste += BigInt(nxt - idx) * BigInt(b) - (prefix[nxt] - prefix[idx]);

            idx = nxt;
            if (idx === n) break;
        }

        if (ans === null || waste < ans)
            ans = waste;
    }

    return ans === null ? -1 : Number(ans % MOD);
};