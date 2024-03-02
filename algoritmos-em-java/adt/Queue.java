package adt;

public class Queue {
    private int[] data;
    private int front;
    private int rear;
    private int max;

    public Queue(int size) {
        data = new int[size];
        front = 0;
        rear = 0;
        this.max = size;
    }

    public void enqueue(int value){
        if (isFull()) {
            throw new IllegalStateException("The queue is full");
        }

        data[rear] = value;
        rear = (rear + 1) % max;
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("The queue is empty");
        }
        int value = data[front];
        front = (front + 1) % max;
        
        return value;
    }

    public boolean isEmpty() {
        return front == rear;
    }

    public boolean isFull() {
        return size() == max;
    }

    public int size() {
        if (isEmpty()) {
            return 0;
        }
        int size = (max - front + rear + 1) % (max + 1);

        return size;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("The queue is empty");
        }
        return data[front];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("The queue is empty");
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % max) {
            System.out.println(data[i]);
        }
        System.out.println(data[rear]);
    }
}
