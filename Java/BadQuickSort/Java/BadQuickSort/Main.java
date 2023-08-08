package Java.BadQuickSort;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        ArrayList<Integer> listToOrder = new ArrayList<>();
        listToOrder.add(1);
        listToOrder.add(12);
        listToOrder.add(4);
        listToOrder.add(77);
        listToOrder.add(5);
        listToOrder.add(64);
        listToOrder.add(99);
        listToOrder.add(3);
        listToOrder.add(52);
        listToOrder.add(45);
        listToOrder.add(74);
        System.out.println(listToOrder);
        QuickSort.quickSort(listToOrder, 0, listToOrder.size()-1);
        System.out.println(listToOrder);
    }
}
