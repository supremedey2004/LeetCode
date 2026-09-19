class Solution {
    static ArrayList<Integer> arr=new ArrayList<>();

    public void preorder(TreeNode root){
        if(root==null) return;
        arr.add(root.val);
        preorder(root.left);
        preorder(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        arr.clear();
        preorder(root);
        return arr;
        
    }
}