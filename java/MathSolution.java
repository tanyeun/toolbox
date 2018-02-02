import java.util.*;

class MathSolution {
  public static void testCase(String status){
     if ( status.equals("Hide") == false ) {
	     System.out.println("##### Get Max Distance Square #####");	
       System.out.println(getMaxDistanceSquare(2,4,2,4));
       System.out.println(getMaxDistanceSquare(1,2,3,4));
     }
  }
  
  static int getMaxDistanceSquare(int A, int B, int C, int D){
    int max = -1; 
    int[] dist = new int[3];
    dist[0] = (A-B)*(A-B) + (C-D)*(C-D); 
    dist[1] = (A-C)*(A-C) + (B-D)*(B-D);
    dist[2] = (A-D)*(A-D) + (B-C)*(B-C);

    for(int i = 0; i < 2; i++)
      max = dist[i] > dist[i+1] ? dist[i] : dist[i+1];

    return max;
  }

}
