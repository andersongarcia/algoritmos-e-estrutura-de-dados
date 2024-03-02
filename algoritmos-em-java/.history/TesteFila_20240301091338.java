import adt.Queue;

public class TesteFila {
    public static void main(String[] args) {
        Queue fila = new Queue(5);
        fila.enqueue(10);
        fila.enqueue(20);
        fila.enqueue(30);
        fila.enqueue(40);
        fila.enqueue(50);
        fila.display();
        System.out.println("Size: " + fila.size());
        System.out.println("Front: " + fila.peek());

        System.out.println("Dequeue: " + fila.dequeue() + " removed from the queue");

        fila.display();

        // Adding more elements to the queue
        int newValue = 60;
        fila.enqueue(newValue);
        System.out.println("Enqueue: " + newValue + " enqueued to the queue");

        fila.display();

        System.out.println("Size: " + queue.size());
        System.out.println("Front: " + queue.peek());

    }
}
