import java.util.*;

class AnagramSolution {	
  static int countEqual(int[] window, int[] target){
      // Make sure window and target have the same length
      if( window.length != target.length )
          return -1;
      int count = 0;
      for(int i=0; i < window.length; i++){
          int diff = Math.abs(window[i] - target[i]);
          count += diff;
      }
      // If return zero, means window and target are identical
      return count;
  }
  
  static int[] countChars(String str){
      int[] counter = new int[26];
      int offset = (int) 'a';
      for(int i=0; i < str.length(); i++){
          char cc = str.charAt(i);
          counter[cc-offset]++;
      }
      return counter;
  }

  public static List<Integer> findInString1(String source, String target)
  {
    List<Integer> result = new LinkedList<Integer>();
    if( target.length() > source.length() )
        return result;
    
    int[] pCount = countChars(target);
    // char count view of the first window
    int[] windowCount = countChars(source.substring(0, target.length()));
    //System.out.println(Arrays.toString(pCount));
    //System.out.println(Arrays.toString(windowCount));
    //System.out.println("=====");
    
    if( countEqual(pCount, windowCount) == 0)
        result.add(0);
    
    for(int i = 1; i < source.length()-target.length()+1; i++) {
        String window = source.substring(i, i+target.length());
        //System.out.println(window);
        windowCount = countChars(window);
        //System.out.println(Arrays.toString(windowCount));
        if( countEqual(pCount, windowCount) == 0)
            result.add(i);
    }
    return result; 
  }
	public static List<Integer> findInString(String source, String target)
	{
    List<Integer> result = new LinkedList<>();
    if( source.length() < target.length() )
      return result;

    // Initialize hashmap for the target string
    HashMap<Character, Integer> map = new HashMap<Character, Integer>();
    for(int i=0; i < target.length(); i++)
    {
      char cc = target.charAt(i);
      if( map.containsKey(cc) ){
        map.put(cc, map.get(cc)+1);
      }else
        map.put(cc, 1);
    }
    int cnt = map.size(); // ***

    Utils.printHash(map);    
    System.out.println(cnt);

    int length = target.length();
    int begin = 0;
    int end = 0;
    while( end < source.length() )
    {
      char cc = source.charAt(end);
      if( map.containsKey(cc) ){
        map.put( cc, map.get(cc)-1 );
        if( map.get(cc) == 0 ) // ***
          cnt--;
      }
      end++;

    Utils.printHash(map);    
    System.out.println(cnt + " " + begin + " " + end);

      while( cnt == 0 ){
        if( (end-begin) == length )
          result.add(begin);
        char dd = source.charAt(begin);
        if ( map.containsKey(dd) ){
          map.put( dd, map.get(dd)+1 );
          if( map.get(dd) > 0 ) // ***
            cnt++;
        }
        begin++;

    Utils.printHash(map);    
    System.out.println(cnt + " " + begin + " " + end);

      }

    }
    
    return result;
	}
}
