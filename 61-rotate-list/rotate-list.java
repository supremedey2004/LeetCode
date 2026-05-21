/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        // Handle base cases: empty list, single node, or no rotation
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // 1. Find the length and the last node
        ListNode lastNode = head;
        int length = 1;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
            length++;
        }

        // 2. Adjust k for cases where k > length
        k = k % length;
        if (k == 0) {
            return head;
        }

        // 3. Make the list circular
        lastNode.next = head;

        // 4. Find the new tail
        // It's located (length - k - 1) nodes from the current head
        ListNode newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail.next;
        }

        // 5. Break the circle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}