from typing import List
from collections import Counter
from math import gcd

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        count = Counter(deck)

        g = 0
        for freq in count.values():
            g = gcd(g, freq)

        return g >= 2