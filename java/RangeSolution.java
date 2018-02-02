import java.util.*;

class RangeSolution {
  public static void testCase(String status) throws Exception {
     if ( status.equals("Hide") == false ) {
	     System.out.println("##### Range #####");	
       Range rr = new Range(0,4);
       //RangeSolution rr = new RangeSolution(-1,Integer.MAX_VALUE);
       System.out.println(rr.length());
     }
  }

}
