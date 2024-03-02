import adt.StackDynamic;

public class TestePilhaDinamica {
    public static void main(String[] args){
        StackDynamic stack = new StackDynamic();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.display();
        System.out.println("Size: " + stack.size());
        System.out.println("Peek: " + stack.peek());

        System.out.println("Pop: " + stack.pop() + " removed from the stack");

        stack.display();

        // Adding more elements to the stack
        stack.push(60);
        System.out.println("Push: " + stack.peek() + " pushed to the stack");

        stack.display();

        System.out.println("Size: " + stack.size());
        System.out.println("Peek: " + stack.peek());
    }
}
