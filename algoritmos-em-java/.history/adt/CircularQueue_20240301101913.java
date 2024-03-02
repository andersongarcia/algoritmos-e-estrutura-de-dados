package adt;

public class CircularQueue {
    private int[] array;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    // Construtor
    public CircularQueue(int capacity) {
        this.capacity = capacity;
        this.array = new int[capacity];
        this.front = 0;
        this.rear = -1; // Fila vazia no início
        this.size = 0;
    }

    // Método para verificar se a fila está vazia
    public boolean isEmpty() {
        return size == 0;
    }

    // Método para verificar se a fila está cheia
    public boolean isFull() {
        return size == capacity;
    }

    // Método para adicionar um elemento à fila
    public void enqueue(int item) {
        if (isFull()) {
            throw new IllegalStateException("A fila está cheia.");
        }
        rear = (rear + 1) % capacity; // Calcula o índice para adicionar o elemento circularmente
        array[rear] = item; // Adiciona o elemento à fila
        size++;
    }

    // Método para remover e retornar o elemento na frente da fila
    public int dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("A fila está vazia.");
        }
        int removedItem = array[front]; // Obtém o elemento a ser removido
        front = (front + 1) % capacity; // Calcula o novo índice para a frente da fila
        size--;
        return removedItem;
    }

    // Método para obter o elemento na frente da fila sem removê-lo
    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("A fila está vazia.");
        }
        return array[front];
    }

    // Método para obter o tamanho atual da fila
    public int size() {
        return size;
    }

    // Método para exibir os elementos da fila
    public void display() {
        if (isEmpty()) {
            System.out.println("A fila está vazia.");
            return;
        }
        System.out.print("Elementos da fila: ");
        for (int )
        System.out.println();
    }
}