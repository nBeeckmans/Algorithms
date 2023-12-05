package Java.BinarySearch;

import java.util.ArrayList;

public class Binary {

    public static <T extends Comparable<T>> int Search(ArrayList<T> list, T objectToFind) {
        int first = 0; 
        int last = list.size()-1;
        while( first < last) {
            int middle = (first + last) / 2; 
            if (objectToFind.compareTo(list.get(middle)) <= 0){
                last = middle; 
            } else {
                first = middle + 1; 
            }
        }
        if (list.get(first).compareTo(objectToFind) != 0) {
            first = -1;
        }
        return first; 
    }   
}
