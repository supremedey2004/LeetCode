class Solution {

    function minWastedSpace($packages, $boxes) {
        $MOD = 1000000007;

        sort($packages);

        $n = count($packages);

        $prefix = array_fill(0, $n + 1, 0);

        for ($i = 0; $i < $n; $i++) {
            $prefix[$i + 1] = $prefix[$i] + $packages[$i];
        }

        $ans = PHP_INT_MAX;

        foreach ($boxes as $supplier) {
            sort($supplier);

            if ($supplier[count($supplier) - 1] < $packages[$n - 1]) {
                continue;
            }

            $waste = 0;
            $idx = 0;

            foreach ($supplier as $b) {
                $next = $this->upperBound($packages, $idx, $b);

                $waste += ($next - $idx) * $b - ($prefix[$next] - $prefix[$idx]);

                $idx = $next;

                if ($idx == $n) {
                    break;
                }
            }

            $ans = min($ans, $waste);
        }

        return $ans == PHP_INT_MAX ? -1 : $ans % $MOD;
    }

    private function upperBound($arr, $start, $target) {
        $l = $start;
        $r = count($arr);

        while ($l < $r) {
            $mid = intdiv($l + $r, 2);

            if ($arr[$mid] <= $target) {
                $l = $mid + 1;
            } else {
                $r = $mid;
            }
        }

        return $l;
    }
}