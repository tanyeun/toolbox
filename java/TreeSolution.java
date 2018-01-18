import java.util.*;

class TreeSolution {
  // Binary Search Tree
  public static TreeNode insert(TreeNode root, int data){
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

  public static void inOrder(TreeNode root){
	if ( root != null ) {
	  inOrder( root.left );
	  System.out.print(root.data + " ");
	  inOrder( root.right );
	}
  }

  public static void postOrder(TreeNode root){
	if ( root != null ) {
	  postOrder( root.left );
	  postOrder( root.right );
	  System.out.print(root.data + " ");
	}
  }

  public static void preOrder(TreeNode root){
	if ( root != null ) {
	  System.out.print(root.data + " ");
	  preOrder( root.left );
	  preOrder( root.right );
	}
  }

  public static void levelOrder(TreeNode root){
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
