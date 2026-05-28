# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[str]
        """
        ans = []

        def dfs(node, path):
            if node is None:
                return

            # add current node value to path
            if path == "":
                path = str(node.val)
            else:
                path += "->" + str(node.val)

            # if leaf node, store path
            if node.left is None and node.right is None:
                ans.append(path)
                return

            dfs(node.left, path)
            dfs(node.right, path)

        dfs(root, "")
        return ans