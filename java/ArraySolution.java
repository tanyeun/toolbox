class ArraySolution {
    // ### Remove Duplicates from Sorted Array
    public static int removeDuplicates(int[] A) 
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

	public static void printArrayIntOfSize(int size, int[] A)
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
