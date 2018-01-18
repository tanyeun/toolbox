import java.util.*;

class Utils {
  public static void printHash(HashMap map){
    for( Object key : map.keySet() )
      System.out.println(key + " = " + map.get(key) );
  }
}
