class Solution {

    fun isValidBST(root: TreeNode?): Boolean {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE)
    }

    fun validate(node: TreeNode?, min: Long, max: Long): Boolean {

        if (node == null) return true

        if (node.`val` <= min || node.`val` >= max)
            return false

        return validate(node.left, min, node.`val`.toLong()) &&
               validate(node.right, node.`val`.toLong(), max)
    }
}