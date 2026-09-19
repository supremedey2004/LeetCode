class Solution {
    static ArrayList<Integer>arr;

    public void preorder(TreeNode root){
        if(root==null) return;
        arr.add(root.val);
        preorder(root.left);
        preorder(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
     arr=new ArrayList<>();
        preorder(root);
        return arr;
        
    }
}