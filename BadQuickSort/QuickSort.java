import java.util.ArrayList;

public class QuickSort{
    /**
     * implementation of QuickSort on a list of Type T, T has to implement Comparable.
     */
    public static <T extends Comparable<T>> void quickSort(ArrayList<T> list, int firstIndex, int lastIndex ){
        int nextMiddleIndex; 
        if ( firstIndex < lastIndex && firstIndex >= 0 && lastIndex < list.size()) {
            nextMiddleIndex = sorting(list, firstIndex, lastIndex); 
            quickSort(list,0, nextMiddleIndex); 
            quickSort(list, nextMiddleIndex + 1, list.size()-1); 
        }
    }
    /**
     * implementation of the sorting part of the algorithm 
     */
    public static <T extends Comparable<T>> int sorting(ArrayList<T> list, int firstIndex,int lastIndex){
        T pivot = list.get( (firstIndex + lastIndex)/2 );
        firstIndex --;
        lastIndex++;
        while( firstIndex < lastIndex ) {
            do {
                firstIndex++; 
            } while ( firstIndex < list.size() && list.get(firstIndex).compareTo(pivot) < 0 ); 
            do {
                lastIndex--;
            } while(lastIndex > -1 && list.get(lastIndex).compareTo(pivot) > 0);
            if (firstIndex < lastIndex) {
                swap(list, firstIndex, lastIndex);
            }
        } 
        return lastIndex; 
    }
    public static <T> void swap(ArrayList<T> list, int firstIndex, int lastIndex) {
        
            T temp = list.remove(firstIndex); 
            list.add(firstIndex, list.remove(lastIndex));
            list.add(firstIndex, temp);

            
    }


}