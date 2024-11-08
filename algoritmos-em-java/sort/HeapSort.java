package sort;

public class HeapSort {
    public static void sort(int[] array) {
        int n = array.length;

        // Constrói o heap (rearranja o array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(array, n, i);
        }

        // Extrai um por um dos elementos do heap
        for (int i = n - 1; i > 0; i--) {
            // Move a raiz atual para o final
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;

            // Chama o heapify no heap reduzido
            heapify(array, i, 0);
        }
    }

    private static void heapify(int[] array, int n, int i) {
        int largest = i; // Inicializa o maior como raiz
        int left = 2 * i + 1; // Esquerda = 2*i + 1
        int right = 2 * i + 2; // Direita = 2*i + 2

        // Se o filho esquerdo é maior que a raiz
        if (left < n && array[left] > array[largest]) {
            largest = left;
        }

        // Se o filho direito é maior que o maior até agora
        if (right < n && array[right] > array[largest]) {
            largest = right;
        }

        // Se o maior não é a raiz
        if (largest != i) {
            swap(array, i, largest);

            // Recursivamente heapify a subárvore afetada
            heapify(array, n, largest);
        }
    }

    private static void swap(int[] array, int i, int largest) {
        int swap = array[i];
        array[i] = array[largest];
        array[largest] = swap;
    }
}
