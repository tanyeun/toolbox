import java.util.*;

class AnagramSolution {	
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
