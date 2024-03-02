package adt;

public class Queue {
    private int[] data;
    private int front;
    private int rear;
    private int max;

    public Queue(int size) {
        data = new int[size];
        front = -1;
        rear = -1;
        this.max = size;
    }

    public void enqueue(int value){
        if (isFull()) {
            throw new IllegalStateException("The queue is full");
        }
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % max;
        data[rear] = value;
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("The queue is empty");
        }
        int value = data[front];

        front = (front+1) % max;
        return value;
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public boolean isFull() {
        int size = size();
        return size == max;
    }

    public int size() {
        if (isEmpty()) {
            return 0;
        }
        int size = (max - front + rear + 1) % max;

        return size;
    }

    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("The queue is empty");
        }
        return data[front];
    }

    public void display() {
        for (int i = front; i <= rear; i++) {
            System.out.println(data[i]);
        }
    }
}
