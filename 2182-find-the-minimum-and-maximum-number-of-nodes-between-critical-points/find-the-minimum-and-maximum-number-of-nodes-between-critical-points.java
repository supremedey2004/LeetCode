class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {

        // Need at least 3 nodes
        if (head == null || head.next == null || head.next.next == null) {
            return new int[]{-1, -1};
        }

        ListNode prev = head;
        ListNode curr = head.next;

        int index = 1;

        int firstCritical = -1;
        int lastCritical = -1;

        int minDistance = Integer.MAX_VALUE;

        while (curr.next != null) {

            // Check local maxima
            boolean isMax =
                    curr.val > prev.val &&
                    curr.val > curr.next.val;

            // Check local minima
            boolean isMin =
                    curr.val < prev.val &&
                    curr.val < curr.next.val;

            if (isMax || isMin) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = index;
                }

                // Calculate distance from previous critical point
                if (lastCritical != -1) {
                    minDistance = Math.min(
                            minDistance,
                            index - lastCritical
                    );
                }

                lastCritical = index;
            }

            prev = curr;
            curr = curr.next;
            index++;
        }

        // Less than 2 critical points
        if (firstCritical == lastCritical) {
            return new int[]{-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;

        return new int[]{minDistance, maxDistance};
    }
}