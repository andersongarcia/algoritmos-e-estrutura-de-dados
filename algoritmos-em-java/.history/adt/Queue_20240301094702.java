package adt;

public class Queue {
    private int[] data;
    private int front;
    private int rear;
    private int max;

    public Queue(int size) {
        data = new int[size+1];
        front = -1;
        rear = -1;
        this.max = size+1;
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

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max;
        }
        
        return value;
    }

    public boolean isEmpty() {
        return front == rear;
    }

    public boolean isFull() {
        int size = size();
        return size == max-1;
    }

    public int size() {
        if (isEmpty()) {
            return 0;
        }
        int size = (rear - front + 1 + max) % max;

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
