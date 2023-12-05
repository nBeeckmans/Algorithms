package Java.LinearSearch;

import java.util.ArrayList;

public class LinearSearch {
    public static <T> int search(ArrayList<T> list, T toFind){
        boolean isNotFound = true;
        int index = 0; 
        while (isNotFound && index < list.size()){
            isNotFound = !list.get(index).equals(toFind);
            index++;
        }
        return isNotFound ? -1 : index; 
    }
}
