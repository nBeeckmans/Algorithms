package Java.SelectionSort;

import java.util.ArrayList;

public class Selection {
    public static <T extends Comparable<T>> void sort(ArrayList<T> list) {
        for (int i = 0; i < list.size() - 1; i++){
            T minimum = list.get(i);
            int position = i;
            int j = i + 1;
            for (; j < list.size(); j++){
                if (list.get(j).compareTo(minimum) < 0){
                    minimum = list.get(j);
                    position =j;
                }
            }
            swap(list, position, i);
        }
    }

    private static <T> void swap (ArrayList<T> list,int i,int j) {
        T temp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, temp);
    } 
}
