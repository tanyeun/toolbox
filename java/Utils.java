import java.util.*;

class Utils {
  public static void printHash(HashMap map){
    for( Object key : map.keySet() )
      System.out.println(key + " = " + map.get(key) );
  }

  public static void printList(ListNode head){
    ListNode current = head;
    while( current.next != null){
      System.out.print(current.data + "=>");
      current = current.next;
    }
    System.out.println(current.data);
  }
}
