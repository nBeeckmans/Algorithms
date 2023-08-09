package Java.BubbleSort;

import java.util.ArrayList;

public class Bubble {
    public static <T extends Comparable<T>> void sort(ArrayList<T> list) {
        boolean isNotSorted = true;  
        int lastIndex = list.size() - 2; 
        while (isNotSorted) {
            isNotSorted = false; 
            for (int i = 0; i < lastIndex; i ++) {
                if (list.get(i).compareTo( list.get(i+1)) > 0) {
                    swap(list, i, i + 1);
                    isNotSorted = true; 
                }
            }
            lastIndex --; 
        }
    } 

    private static <T> void swap (ArrayList<T> list,int i,int j) {
        T temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    } 
}
