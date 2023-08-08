import java.util.ArrayList;

public class QuickSort{
    /**
     * implementation of QuickSort on a list of Type T, T has to implement Comparable.
     */
    public static <T extends Comparable<T>> void quickSort(ArrayList<T> list, int firstIndex, int lastIndex ){
        if ( firstIndex < lastIndex) {
            int nextMiddleIndex = sorting(list, firstIndex, lastIndex); 
            quickSort(list,firstIndex, nextMiddleIndex); 
            quickSort(list, nextMiddleIndex + 1, lastIndex); 
        }
    }
    /**
     * implementation of the sorting part of the algorithm 
     */
    public static <T extends Comparable<T>> int sorting(ArrayList<T> list, int firstIndex,int lastIndex){
        T pivot = list.get( (firstIndex + lastIndex)/2 );
        firstIndex--;
        lastIndex++;
        while( firstIndex < lastIndex ) {
            do {
                firstIndex++; 
            } while (list.get(firstIndex).compareTo(pivot) < 0 ); 
            do {
                lastIndex--;
            } while(list.get(lastIndex).compareTo(pivot) > 0);
            if (firstIndex < lastIndex) {
                swap(list, firstIndex, lastIndex);
            }
        } 
        System.out.println(list);
        return lastIndex; 
    }
    /**
     * implementation of the swaping method. 
     */
    public static <T> void swap(ArrayList<T> list, int firstIndex, int lastIndex) {
            T temp = list.get(firstIndex); 
            list.set(firstIndex, list.get(lastIndex));
            list.set(lastIndex, temp);       
    }
}