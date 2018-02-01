/*
Requirements:
Define a class to represent a range of integers and operations on them.
The range is defined as closed on the left, open on the right, e.g.
Range(6,8) represents the range [6,8), which is the set {6,7}.

Implement the following methods for this class:
length(): return the length of the range
contains(a): return true if the argument "a" is an integer in the range.
intersects(r): return true if the argument "r" is a range that intersects this range,
        i.e., true if the ranges have any values in common
*/

import java.io.*;

class RangeSolution{
  int left;
  int right;
  RangeSolution(int start, int end){
     	 this.left = start;
       this.right = end;
  }

  // Say Range(-1, MAXINT)
  // end - start will be MAXINT+1 => BANG!!
  public int length() throws Exception {
    if ( ( this.right - this.left ) < 0 )
			throw new Exception("Overflow");	

    return (this.right - this.left);
  }
  
  boolean contains(int number){
    if( number < this.left || number > this.right ){
      return false;
    } else
      return true;
  }
  
  boolean intersects( RangeSolution rr){
    int left = rr.left;
    int right = rr.right;
    
    if( left < this.left ){
      if( right > this.left && right <= this.right )
        return true;
      else
        return false;
    } else if ( left >= this.left && left <= this.right)
      return true;
    else
      return false;
  }
}

class MyCode {
  public static void main (String[] args) {
    System.out.println("Hello Java");
  }
}

