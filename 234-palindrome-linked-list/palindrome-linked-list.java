class Solution {
     public ListNode reverseList(ListNode head) {
        ListNode curr=head;
        ListNode pre=null;
        ListNode next=head;

        while(curr!=null){
            next=curr.next;
            curr.next=pre;
            pre=curr;
            curr=next;
        }

        return pre;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        ListNode j=reverseList(slow);
        ListNode i=head;
        while(j!=null){
            if(i.val!=j.val) {
                return false;
            }
            i=i.next;
            j=j.next;
        
        }
        return true;
    }
}