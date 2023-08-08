package Insertion;

import java.util.ArrayList;

public class Insertion{

    public static <T extends Comparable<T>>void sort(ArrayList<T> list){
        for (int i = 1; i < list.size();i++) {
            insert(list, i); 
            System.out.println(list);
        }
    }

    private static <T extends Comparable<T>> void insert(ArrayList<T> list, int i) {
        int j = i - 1;
        T temp = list.get(i); 

        while (j >= 0 && list.get(j).compareTo(temp) > 0 ){
            j = moveElements(list, j); 
        }
        list.set(j + 1, temp);
    }

    private static <T extends Comparable<T>> int moveElements(ArrayList<T> list, int j) {
        T lastElement = list.get(j); 
        list.set(j + 1 , lastElement);
        j = j - 1;
        return j;
    }
}