public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tempa=headA;
        ListNode tempb=headB;
        int lena=0;
        int lenb=0;
        // Calculate Length of LL A And LL B

        while(tempa!=null){
            tempa=tempa.next;
            lena++;
        }
         while(tempb!=null){
            tempb=tempb.next;
            lenb++;
        }
        tempa=headA;
        tempb=headB;

        // Then Calculate the diffference 
        if(lena> lenb){
            for(int i=0;i<lena-lenb;i++){
                tempa=tempa.next;
            }
        }
        else{
            for(int i=0;i<lenb-lena;i++){
                tempb=tempb.next;
            }
        }
        while(tempa!=tempb){
            tempa=tempa.next;
            tempb=tempb.next;
        }
        return tempa;
    }
}