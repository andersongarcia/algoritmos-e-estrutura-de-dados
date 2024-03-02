import adt.CircularQueue;
import adt.Queue;

public class TesteFila {
    public static void main(String[] args) {
        Queue queue = new CircularQueue(5);
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.enqueue(40);
        queue.enqueue(50);
        queue.display();
        System.out.println("Size: " + queue.size());
        System.out.println("Front: " + queue.peek());

        System.out.println("Dequeue: " + queue.dequeue() + " removed from the queue");

        queue.display();

        // Adding more elements to the queue
        int newValue = 60;
        queue.enqueue(newValue);
        System.out.println("Enqueue: " + newValue + " enqueued to the queue");

        queue.display();

        System.out.println("Size: " + queue.size());
        System.out.println("Front: " + queue.peek());

    }
}
