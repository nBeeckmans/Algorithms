package Java.LinkedLists;

import java.util.NoSuchElementException;

public class StackedList <T extends Comparable<T>> {

    protected class  Element <T extends Comparable<T>> {
        T value;
        Element<T> next; 

        public Element(T value) {
            this.value = value; 
        }
        public Element(T value, Element<T> next) {
            this(value);
            this.next = next; 
        }
        public void deleteNext(){
            next = null; 
        }
    }  


    Element<T> firstElement = null; 
    Element<T> lastElement = null ; 
    
    public StackedList() {

    }

    public void add(T element) {
        if (firstElement == null) {
            firstElement = new Element<T>(element);
            lastElement = firstElement; 
        } else {
            Element<T> temp = new Element<T>(element, firstElement);
            firstElement = temp;
        }
    }

    public void removeLast() {
        if ( firstElement == null || lastElement == null){
            throw new NoSuchElementException();
        }
        if (firstElement != lastElement){
            Element<T> before = firstElement; 
            Element<T> next = before.next; 
            while ( next != lastElement ) {
                next = next.next; 
                before = before.next;
            }
            before.next = null; 
            lastElement = before; 
        } else {
            firstElement = null; 
            lastElement = null;
        }
       
    }
}
