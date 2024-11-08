import sort.HeapSort;

public class TesteHeapSort {
    public static void main(String[] args) {
        int[] array = { 12, 11, 13, 5, 6, 7 };

        System.out.println("Array original:");
        printArray(array);

        HeapSort.sort(array);

        System.out.println("Array ordenado:");
        printArray(array);
    }

    private static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}
