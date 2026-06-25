#include <iostream>

using namespace std;

// Função para ajustar o heap para baixo (Heapify Down)
// n é o tamanho do heap, i é o índice do nó pai a ser ajustado
void heapify(int arr[], int n, int i) {
    int maior = i;          // Inicializa o maior elemento como a raiz/pai
    int esquerdo = 2 * i + 1;  // Índice do filho esquerdo
    int direito = 2 * i + 2;   // Índice do filho direito

    // Se o filho esquerdo for maior que o pai atual
    if (esquerdo < n && arr[esquerdo] > arr[maior]) {
        maior = esquerdo;
    }

    // Se o filho direito for maior que o maior encontrado até agora
    if (direito < n && arr[direito] > arr[maior]) {
        maior = direito;
    }

    // Se o maior não for a raiz original (pai), faz a troca e continua ajustando
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Recursivamente ajusta a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal do HeapSort
void heapSort(int arr[], int n) {
    // 1. CONSTRUÇÃO DO MAX-HEAP (Rearranja o vetor)
    // Começa do último nó pai (n/2 - 1) até a raiz (0)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 2. EXTRAÇÃO DOS ELEMENTOS DO HEAP (Ordenação)
    // Um por um, extrai o maior elemento da raiz e o move para o final
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (o maior elemento) para o fim do vetor
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama o heapify na raiz reduzindo o tamanho considerado do heap para 'i'
        heapify(arr, i, 0);
    }
}

// Função auxiliar para exibir o vetor na tela
void exibirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Digite a quantidade de elementos do vetor: ";
    cin >> n;

    // Alocação dinâmica para o vetor baseado no tamanho digitado
    int* vetor = new int[n];

    cout << "Digite os " << n << " numeros inteiros:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> vetor[i];
    }

    cout << "\n----------------------------------------" << endl;
    cout << "Vetor ANTES da ordenacao: " << endl;
    exibirVetor(vetor, n);
    cout << "----------------------------------------" << endl;

    // Executa o HeapSort (que constrói o Max-Heap e ordena)
    heapSort(vetor, n);

    cout << "Vetor DEPOIS da ordenacao (HeapSort): " << endl;
    exibirVetor(vetor, n);
    cout << "----------------------------------------" << endl;

    // Libera a memória alocada
    delete[] vetor;

    return 0;
}