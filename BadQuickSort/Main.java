import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        ArrayList<Integer> listATrier = new ArrayList<>();
        listATrier.add(1);
        listATrier.add(12);
        listATrier.add(4);
        listATrier.add(77);
        listATrier.add(5);
        listATrier.add(64);
        listATrier.add(99);
        listATrier.add(3);
        listATrier.add(52);
        listATrier.add(45);
        listATrier.add(74);
        System.out.println(listATrier);
        QuickSort.quickSort(listATrier, 0, listATrier.size()-1);
        System.out.println(listATrier);
    }
}
