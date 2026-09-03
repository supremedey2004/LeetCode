class Solution {

    public ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode pre = null;
        ListNode next = head;

        while (curr != null) {
            next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }

    public ListNode reverseBetween(ListNode head, int left, int right) {

        if (head == null || left == right) {
            return head;
        }

        ListNode temp1 = head;

        // Move temp1 to node BEFORE left
        for (int i = 1; i < left - 1; i++) {
            temp1 = temp1.next;
        }

        // Special case: left = 1
        if (left == 1) {
            ListNode h1 = head;
            ListNode temp = head;

            for (int i = 1; i < right; i++) {
                temp = temp.next;
            }

            ListNode h2 = temp.next;
            temp.next = null;

            head = reverseList(h1);

            h1.next = h2;

            return head;
        }

        // temp1 = node before left
        ListNode h1 = temp1.next;

        ListNode temp2 = h1;

        // Move temp2 to right node
        for (int i = left; i < right; i++) {
            temp2 = temp2.next;
        }

        // Save node after right
        ListNode h2 = temp2.next;

        // Break the list
        temp2.next = null;

        // Reverse left -> right
        ListNode list = reverseList(h1);

        // Reconnect
        temp1.next = list;
        h1.next = h2;

        return head;
    }
}