package adt;

public class StackDynamic {
    private Node top;

    public StackDynamic() {
        top = null;
    }

    public void push(int value) {
        Node newNode = new Node(value);
        newNode.setNext(top);
        top = newNode;
    }

    public int pop() {
        if (isEmpty()) {
            throw new IllegalStateException("The stack is empty");
        }
        int value = top.getData();
        top = top.getNext();
        return value;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("The stack is empty");
        }
        return top.getData();
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void display() {
        Node current = top;
        while (current != null) {
            System.out.println(current.getData());
            current = current.getNext();
        }
    }

    public int size() {
        int count = 0;
        Node current = top;
        while (current != null) {
            count++;
            current = current.getNext();
        }
        return count;
    }

    public void clear() {
        top = null;
    }
}
