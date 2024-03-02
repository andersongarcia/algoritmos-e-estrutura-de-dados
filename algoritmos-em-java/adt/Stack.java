package adt;

public class Stack {
    private int[] data;
    private int top;

    public Stack(int size) {
        data = new int[size];
        top = -1;
    }

    public void push(int value) {
        if (top == data.length - 1) {
            throw new IllegalStateException("The stack is empty");
        }
        data[++top] = value;
    }

    public int pop() {
        if (top == -1) {
            throw new IllegalStateException("The stack is empty");
        }
        return data[top--];
    }

    public int peek() {
        if (top == -1) {
            throw new IllegalStateException("The stack is empty");
        }
        return data[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == data.length - 1;
    }

    public int size() {
        return top + 1;
    }

    public void display() {
        for (int i = top; i >= 0; i--) {
            System.out.println(data[i]);
        }
    }
    
}
