from collections import defaultdict

class Solution:
    def calcEquation(self, equations, values, queries):
        graph = defaultdict(list)

        # Build graph
        for (a, b), val in zip(equations, values):
            graph[a].append((b, val))
            graph[b].append((a, 1 / val))

        def dfs(src, dst, visited):
            if src == dst:
                return 1.0

            visited.add(src)

            for nei, weight in graph[src]:
                if nei not in visited:
                    ans = dfs(nei, dst, visited)
                    if ans != -1:
                        return weight * ans

            return -1

        res = []

        for a, b in queries:
            if a not in graph or b not in graph:
                res.append(-1.0)
            elif a == b:
                res.append(1.0)
            else:
                res.append(dfs(a, b, set()))

        return res