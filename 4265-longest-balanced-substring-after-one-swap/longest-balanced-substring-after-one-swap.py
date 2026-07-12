class Solution:
    def longestBalanced(self, s: str) -> int:
        cnt0 = s.count('0')
        cnt1 = len(s) - cnt0

        pos = {0: [-1]}
        pre = 0
        ans = 0

        for i, ch in enumerate(s):
            if ch == '1':
                pre += 1
            else:
                pre -= 1

            pos.setdefault(pre, []).append(i)

            # Already balanced
            ans = max(ans, i - pos[pre][0])

            # Substring has two extra 1's
            if pre - 2 in pos:
                p = pos[pre - 2]
                if (i - p[0] - 2) // 2 < cnt0:
                    ans = max(ans, i - p[0])
                elif len(p) > 1:
                    ans = max(ans, i - p[1])

            # Substring has two extra 0's
            if pre + 2 in pos:
                p = pos[pre + 2]
                if (i - p[0] - 2) // 2 < cnt1:
                    ans = max(ans, i - p[0])
                elif len(p) > 1:
                    ans = max(ans, i - p[1])

        return ans