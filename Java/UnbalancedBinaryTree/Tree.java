package Java.UnbalancedBinaryTree;

import java.util.ArrayList;

public class Tree <T extends Comparable<T>> {
    Node <T> firstElement;

    protected class Node <T extends Comparable<T>>{
        T value;
        Node<T> leftNode; 
        Node<T> rightNode; 
    }

    public <T extends Comparable<T>> void giveSortedArray(ArrayList<Node<T>> list, Node<T> node){
        giveSortedArray(list, node.leftNode);
        list.add(node);
        giveSortedArray(list, node.rightNode);
    }

    public <T extends Comparable<T>> void add(Node<T> node) {

    } 
    
}
