#include <iostream>

using namespace std;

class No {
public:
    int dado;
    No* prox;

    No(int valor) {
        dado = valor;
        prox = NULL;
    }
};

class ListaEncadeada {
private:
    No* cabeca;   // ponteiro para o primeiro nó da lista

public:
    // criar uma lista vazia
    ListaEncadeada() {
        cabeca = NULL;
    }

    // limpa a memória
    ~ListaEncadeada() {
        while (cabeca != NULL) {
            No* temp = cabeca;
            cabeca = cabeca->prox;
            delete temp;
        }
    }

    // verificar se está vazia
    bool vazia() const {
        return cabeca == NULL;
    }

    // obter o tamanho
    int getTamanho() const {
        int cont = 0;
        No* atual = cabeca;
        while (atual != NULL) {
            cont++;
            atual = atual->prox;
        }
        return cont;
    }

    // obter o valor do elemento de uma determinada posição
    int getElemento(int posicao) const {
        No* atual = cabeca;
        int tam = getTamanho();
        if (posicao <= tam && posicao > 0) {
            for (int i = 1; i < posicao; ++i) {
                atual = atual->prox;
            }
            return atual->dado;
        } else {
            return -1; // posição inválida
        }
    }

    // alterar o valor do elemento de uma determinada posição
    void altElemento(int posicao, int valor) {
        No* atual = cabeca;
        if (posicao <= getTamanho() && posicao > 0) {
            for (int i = 1; i < posicao; ++i) {
                atual = atual->prox;
            }
            atual->dado = valor;
        }
    }

    // inserir um elemento
    void inserir(int posicao, int valor) {
        if (posicao < 1 || posicao > getTamanho() + 1) {
            cout << "Posição inválida para inserção." << endl;
            return;
        }
        No* novoNo = new No(valor);
        if (posicao == 1) {
            novoNo->prox = cabeca;
            cabeca = novoNo;
        } else {
            No* atual = cabeca;
            for (int i = 1; i < posicao - 1; ++i) {
                atual = atual->prox;
            }
            novoNo->prox = atual->prox;
            atual->prox = novoNo;
        }
    }

    // remover um elemento
    int remover(int posicao) {
        if (posicao < 1 || posicao > getTamanho()) {
            cout << "Posição inválida para remoção." << endl;
            return -1;
        }
        No* aDeletar;
        int valorRemovido;
        if (posicao == 1) {
            aDeletar = cabeca;
            cabeca = cabeca->prox;
        } else {
            No* atual = cabeca;
            for (int i = 1; i < posicao - 1; ++i) {
                atual = atual->prox;
            }
            aDeletar = atual->prox;
            atual->prox = aDeletar->prox;
        }
        valorRemovido = aDeletar->dado;
        delete aDeletar;
        return valorRemovido;
    }

    // imprimir a lista
    void imprimirLista() const {
        No* atual = cabeca;
        while (atual != NULL) {
            cout << atual->dado << " -> ";
            atual = atual->prox;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ListaEncadeada lista;

    // mostrar que a lista está vazia
    if (lista.vazia()) {
        cout << "Lista vazia\nTamanho: " << lista.getTamanho() << endl;
    }

    // inserir na lista
    cout << "Inserir elementos na lista\n";
    lista.inserir(1, 13);
    lista.inserir(2, 31);
    lista.inserir(3, 22);
    lista.inserir(4, 33);
    lista.inserir(5, 331);

    // exibir o tamanho da lista no início
    cout << "Tamanho: " << lista.getTamanho() << endl;

    // exibir lista
    cout << "Elementos da lista: ";
    lista.imprimirLista();

    // procurar elemento
    int proc = lista.getElemento(10);
    if (proc != -1) {
        cout << "Elemento da posição 10: " << proc << endl;
    } else {
        cout << "Posição não encontrada\n";
    }

    // alterar elemento da lista
    cout << "Elemento: " << lista.getElemento(3);
    lista.altElemento(3, 131);
    cout << " alterado para: " << lista.getElemento(3) << endl;

    // remover elemento
    int elementoRemovido = lista.remover(1);
    if (elementoRemovido != -1) {
        cout << "Elemento removido: " << elementoRemovido << endl;
        cout << "Tamanho atual da lista: " << lista.getTamanho() << endl;
    }

    // exibir lista
    cout << "Elementos da lista: ";
    lista.imprimirLista();

    return 0;
}
