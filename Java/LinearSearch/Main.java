package Java.LinearSearch;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        arrayList.add(0);
        arrayList.add(7);
        arrayList.add(6);
        arrayList.add(1);
        arrayList.add(4);
        arrayList.add(3);

        System.out.println(LinearSearch.search(arrayList, 3));
        System.out.println(LinearSearch.search(arrayList, 10));


    }

}
