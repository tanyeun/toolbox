import java.util.*;

class ArraySolution {

  public static void testCase(String status){
     if ( status.equals("Hide") == false ) {
	     int[] arrayIntSorted = {1, 2, 2, 3, 3, 6, 9, 9};	
		   int[] arrayInt = {4, 6, 5, 7, 2, 1, 3};

	     System.out.println("##### Remove Duplicates from Sorted Array #####");	
	     System.out.println(Arrays.toString( arrayIntSorted ));	
       int size = removeDuplicates(arrayIntSorted);
       printArrayIntOfSize(size, arrayIntSorted);

	     System.out.println("##### Rotate Array #####");	
       int[] arr = {1, 2, 3, 4, 5, 6, 7};
       System.out.println(Arrays.toString(arr));
       int shift = 13;
       rotateRight(arr, shift); 
       System.out.println(Arrays.toString(arr) + " <== Rotate Right by " + shift);
       rotateLeft(arr, shift); 
       System.out.println(Arrays.toString(arr) + " <== Rotate Left by " + shift);

	     System.out.println("##### Rotate Array 2D #####");	
       //int[][] arr2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
       int[][] arr2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
       // System.out.println(Arrays.deepToString(arr2)); // This will print the 2D array in 1D
       print2D(arr2);
       rotateRight2D(arr2);
       print2D(arr2);
     }
  }

  // ### Remove Duplicates from Sorted Array
  static int removeDuplicates(int[] A) 
  {
      int length = A.length;

      if (length == 0) 
      {
          return 0;
      }
      int index = 0;

      for(int i = 1; i < length; i++)
      {
          if(A[index] != A[i])
          {
              A[++index] = A[i];
          }
      }
	    // only from 0~index+1 has distinct values
      return index + 1;
  }

  // Rotate right 90 degree of the given nxn array
  static void rotateRight2D(int[][] matrix)
  {
    int nn = matrix[0].length;
    for(int j=0; j < nn/2; j++ ) {
      for(int i=j; i < nn-1-j; i++) {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[nn-1-i][j];
        matrix[nn-1-i][j] = matrix[nn-1-j][nn-1-i];
        matrix[nn-1-j][nn-1-i] = matrix[i][nn-1-j];
        matrix[i][nn-1-j] = tmp;
      }
    }
  }

	static void rotateRight( int[] nums, int k )
  {
    int length = nums.length;
    if ( k > length )
      k = k%length;

    int[] result = new int[length];

    // void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
    System.arraycopy(nums, 0, result, k, length-k);
    System.arraycopy(nums, length-k, result, 0, k);

    System.arraycopy(result, 0, nums, 0, length);
  }

	static void rotateLeft( int[] nums, int k )
  {
    int length = nums.length;
    if ( k > length )
      k = k%length;

    int[] result = new int[length];

    // void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)
    System.arraycopy(nums, 0, result, length-k, k);
    System.arraycopy(nums, k, result, 0, length-k);

    System.arraycopy(result, 0, nums, 0, length);
  }

  static void print2D(int[][] matrix)
  {
    // matrix[x][y]
    System.out.println("[");
    for(int i=0; i < matrix.length; i++)
    {
      System.out.println("  " +Arrays.toString(matrix[i]));
    }
    System.out.println("]");
  }

	static void printArrayIntOfSize(int size, int[] A)
  {
      System.out.print("[");
	    for(int i = 0; i < size; i++ )
      {
        System.out.print(A[i]);
        if ( i+1 < size )
          System.out.print(", ");
      }
      System.out.print("]\n");
  }

	public static <T> void printArrayOfSize(int size, T[] A)
    {
        System.out.print("[ ");
		for(int i = 0; i < size; i++ )
        {
          System.out.print(A[i]);
          System.out.print(", ");
        }
        System.out.print(" ]");
    }
}
