import java.util.*;

class TreeSolution {
  public static void testCase(String status){
     if ( status.equals("Hide") == false ) {
		   int[] arrayInt = {4, 6, 5, 7, 2, 1, 3};

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
		   inOrder(root);
		   System.out.println();

		   System.out.print("postOrder: ");
		   postOrder(root);
		   System.out.println();

		   System.out.print("preOrder: ");
		   preOrder(root);
		   System.out.println();

		   System.out.print("levelOrder: ");
		   levelOrder(root);
		   System.out.println();
     }
  }
  // Binary Search Tree
  static TreeNode insert(TreeNode root, int data){
	  if ( root == null )
	    return new TreeNode(data);
    else
	  {
	    TreeNode cur; // the new node
	    if ( root.data >= data ){
	  	  cur = insert(root.left, data);
	  	  root.left = cur;
	    }else{
	  	  cur = insert(root.right, data);
	  	  root.right = cur;
	    }
	    return root;
	  }
  }

  static void inOrder(TreeNode root){
	  if ( root != null ) {
	    inOrder( root.left );
	    System.out.print(root.data + " ");
	    inOrder( root.right );
	  }
  }

  static void postOrder(TreeNode root){
	  if ( root != null ) {
	    postOrder( root.left );
	    postOrder( root.right );
	    System.out.print(root.data + " ");
	  }
  }

  static void preOrder(TreeNode root){
	  if ( root != null ) {
	    System.out.print(root.data + " ");
	    preOrder( root.left );
	    preOrder( root.right );
	  }
  }

  static void levelOrder(TreeNode root){
	LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
	  if ( root != null ){
	    queue.addLast(root);
	    while ( !queue.isEmpty() )
	    {
	  	  TreeNode node = queue.removeFirst();
	      System.out.print(node.data + " ");
	  	if( node.left != null )
	  	  queue.addLast(node.left); 
	  	if( node.right != null )
	  	  queue.addLast(node.right); 
	    }
	  }
  }
}
