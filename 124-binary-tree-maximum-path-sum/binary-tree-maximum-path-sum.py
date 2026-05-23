# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root):
        self.ans = float('-inf')

        def dfs(node):
            if not node:
                return 0

            # Ignore negative paths
            left = max(dfs(node.left), 0)
            right = max(dfs(node.right), 0)

            # Path passing through current node
            current_sum = node.val + left + right

            # Update maximum answer
            self.ans = max(self.ans, current_sum)

            # Return max single path
            return node.val + max(left, right)

        dfs(root)
        return self.ans