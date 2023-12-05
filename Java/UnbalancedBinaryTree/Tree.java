package Java.UnbalancedBinaryTree;

import java.util.ArrayList;

public class Tree <T extends Comparable<T>> {
    Node rootNode;

    protected class Node {
        T value;
        Node leftNode; 
        Node rightNode; 
    }

    public void giveSortedArray(ArrayList<Node> list, Node node){
        if (node != null ) {
            giveSortedArray(list, node.leftNode);
            list.add(node);
            giveSortedArray(list, node.rightNode);
        }
    }

    public void add(T valueToAdd) {
        Node next = valueToAdd.compareTo(rootNode.value) > 0 
                ? rootNode.leftNode 
                : rootNode.rightNode;
                
        while (next != null) {
            //next = next.value.compareTo(valueToAdd) >

        }
    } 
    
}
