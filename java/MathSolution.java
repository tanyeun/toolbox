import java.util.*;

class MathSolution {
  public static void testCase(String status){
     if ( status.equals("Hide") == false ) {
	     System.out.println("##### Get Max Distance Square #####");	
       System.out.println(getMaxDistanceSquare(2,4,2,4));
       System.out.println(getMaxDistanceSquare(1,2,3,4));

       System.out.println();
		   int[] movies1 = {6, 1, 4, 6, 3, 2, 7, 4};
		   int[] movies2 = {10, 19, 15};
	     System.out.println("##### Get Max Distance Square #####");	
       System.out.println(getMaxMoviesWatched(movies1, 3, 2));
       System.out.println(getMaxMoviesWatched(movies2, 2, 2));
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

  static int getMaxMoviesWatched(int[] movies, int K, int L){
    int length = movies.length;
    if ( length < K+L )
      return -1;

    int maxK = 0;
    int indK = 0;
    for(int i = 0; i <= length-K; i++){
      int value = 0;
      for(int j = i; j < K+i; j++)
        value += movies[j];

      if ( value > maxK ){
        maxK = value;
        indK = i;
      }
    }

    int maxL = 0;
    for(int i = 0; i <= length-L; i++){
      int value = 0;
      if( i == indK )
        i += K;

      for(int j = i; j < L+i; j++)
        value += movies[j];

      if ( value > maxL ){
        maxL = value;
      }
    }

    return maxK + maxL;

  }
}
