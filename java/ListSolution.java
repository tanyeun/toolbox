import java.util.*;

class ListSolution {
  public ListNode insert(ListNode head, ListNode node){
    ListNode current = head;
    while( current.next != null ){
      current = current.next;
    }
    current.next = node;
    node.next = null;
  }
}
