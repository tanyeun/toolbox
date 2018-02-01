import java.util.*;

class Solution
{
	public static void main(String[] args){
    try {
		  System.out.println("Hello Java");

      ArraySolution.testCase("Hide");
	    //System.out.println("##### Tree Traversal #####");	
		  //TreeNode root=null;
		  //// Construct BST
		  ///*              4
      //     *            /   \
		  // *           2     6
		  // *          / \   /  \
		  // *         1  3  5    7
		  // */
		  //for(int i = 0; i < arrayInt.length; i++ ){
		  //  root = TreeSolution.insert(root, arrayInt[i]); 
		  //}
		  //System.out.print("inOrder: ");
		  //TreeSolution.inOrder(root);
		  //System.out.println();
		  //System.out.print("postOrder: ");
		  //TreeSolution.postOrder(root);
		  //System.out.println();
		  //System.out.print("preOrder: ");
		  //TreeSolution.preOrder(root);
		  //System.out.println();
		  //System.out.print("levelOrder: ");
		  //TreeSolution.levelOrder(root);
		  //System.out.println();

	    System.out.println("##### Anagrams #####");	
      String source = "abcdabc";
      String target = "abc";
      //String source = "cbaebabacd";
      //String target = "abc";
      //String source = "cbeaccbachabaababcba";
      //String target = "abc";
      List<Integer> ll = AnagramSolution.findInString1(source, target);
      System.out.println(ll.toString());
      
	    System.out.println("##### Range #####");	
      RangeSolution rr = new RangeSolution(0,4);
      //RangeSolution rr = new RangeSolution(-1,Integer.MAX_VALUE);
      System.out.println(rr.length());

	    System.out.println("##### Rotate Array #####");	
      int[] arr = {1, 2, 3, 4, 5, 6, 7};
      System.out.println(Arrays.toString(arr));
      int shift = 13;
      ArraySolution.rotateRight(arr, shift); 
      System.out.println(Arrays.toString(arr) + " <== Rotate Right by " + shift);
      ArraySolution.rotateLeft(arr, shift); 
      System.out.println(Arrays.toString(arr) + " <== Rotate Left by " + shift);

	    System.out.println("##### Rotate Array 2D #####");	
      //int[][] arr2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
      int[][] arr2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
      // System.out.println(Arrays.deepToString(arr2)); // This will print the 2D array in 1D
      ArraySolution.print2D(arr2);
      ArraySolution.rotateRight2D(arr2);
      ArraySolution.print2D(arr2);

    } catch(Exception e){
      System.out.println(e.getMessage());
    }
	}
}
