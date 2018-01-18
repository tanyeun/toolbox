import java.util.*;

class Solution
{
	public static void main(String[] args){
		System.out.println("Hello Java");
	    int[] arrayIntSorted = {1, 2, 2, 3, 3, 6, 9, 9};	
		int[] arrayInt = {4, 6, 5, 7, 2, 1, 3};

	    System.out.println("##### Remove Duplicates from Sorted Array #####");	
	    System.out.println(Arrays.toString( arrayIntSorted ));	
        int size = ArraySolution.removeDuplicates(arrayIntSorted);
        ArraySolution.printArrayIntOfSize(size, arrayIntSorted);

	  System.out.println("##### Tree Traversal #####");	
		TreeNode root=null;
		// Construct BST
		/*              4
         *            /   \
		 *           2     6
		 *          / \   /  \
		 *         1  3  5    7
		 */
		for(int i = 0; i < arrayInt.length; i++ ){
		  root = TreeSolution.insert(root, arrayInt[i]); 
		}
		System.out.print("inOrder: ");
		TreeSolution.inOrder(root);
		System.out.println();
		System.out.print("postOrder: ");
		TreeSolution.postOrder(root);
		System.out.println();
		System.out.print("preOrder: ");
		TreeSolution.preOrder(root);
		System.out.println();
		System.out.print("levelOrder: ");
		TreeSolution.levelOrder(root);
		System.out.println();

	  System.out.println("##### Anagrams #####");	
    String source = "abbabb";
    String target = "ab";
    //String source = "cbaebabacd";
    //String target = "abc";
    //String source = "cbeaccbachabaababcba";
    //String target = "abc";
    List<Integer> ll = AnagramSolution.findInString1(source, target);
    System.out.println(ll.toString());
	}
}
