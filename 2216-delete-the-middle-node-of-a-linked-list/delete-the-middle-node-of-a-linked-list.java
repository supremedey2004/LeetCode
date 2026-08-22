class Solution {
    public ListNode deleteMiddle(ListNode head) {

        if (head.next == null) {
            return null;
        }
        
        ListNode slow=head;
        ListNode fast=head;
        ListNode temp=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        while(temp.next!=slow){
                temp=temp.next;
            }
            temp.next=slow.next;
        return head;

    }
}