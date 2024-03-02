package adt;

public class QueueDynamic {
    private Node front;
    private Node rear;

    public QueueDynamic() {
        front = null;
        rear = null;
    }

    public void enqueue(int value){
        Node newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }else{
            rear.setNext(newNode);
            rear = newNode;
        }
    }

    public int dequeue(){
        if (isEmpty()) {
            throw new IllegalStateException("The stack is empty");
        }
        int data = front.getData();
        front = front.getNext();

        return data;
    }

    public int peek(){
        if (isEmpty()) {
            throw new IllegalStateException("The stack is empty");
        }
        return front.getData();
    }

    public boolean isEmpty(){
        return front == null;
    }

    public void display() {
        Node current = front;
        while (current != null) {
            System.out.println(current.getData());
            current = current.getNext();
        }
    }

    public int size(){
        int size = 0;
        Node current = front;
        while (current != null) {
            size++;
            current = current.getNext();
        }

        return size;
    }
}
