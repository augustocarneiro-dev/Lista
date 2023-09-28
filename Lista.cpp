#include<stdio.h>

struct No {

    int valor;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No *inicio, *fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return inicio == NULL;
    }

    void inserirInicio(int valor) { // O(1)
        n++;
        No *novo = new No(valor);
        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }
        novo->prox = inicio;
        inicio = novo;
    }

    void inserirFinal(int valor) { // O(1)
        n++;
        No *novo = new No(valor);
        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }
        fim->prox = novo;
        fim = novo;
    }

    // 1. Criar um método que recebe um número N e remove os N últimos elementos da lista.
    void removerUltimosN(int N) { // O(n)
        if (N >= n) {
            while (!vazia()) removerInicio();
            return;
        }
        No *aux = inicio;
        for (int i = 1; i < n - N; i++) {
            aux = aux->prox;
        }
        while (aux->prox != NULL) {
            No *temp = aux->prox;
            aux->prox = temp->prox;
            if (temp == fim) fim = aux;
            delete temp;
            n--;
        }
    }

    // 2. Crie um método que remove o segundo elemento da lista.
    void removerSegundo() { // O(1)
        if (n <= 1) return;
        No *temp = inicio->prox;
        inicio->prox = temp->prox;
        if (temp == fim) fim = inicio;
        delete temp;
        n--;
    }

    // 3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.
    void inserirTamanhoFinal() { // O(1)
        inserirFinal(n);
    }

    // 4. Crie um método que receba um número N e insira na lista todos os números de 1 até N.
    void inserirAteN(int N) { // O(n)
        for (int i = 1; i <= N; i++) {
            inserirFinal(i);
        }
    }

    // 5. Crie um método que insere um elemento sempre na penúltima posição da lista.
    void inserirPenultimaPos(int valor) { // O(n)
        if (n <= 1) return;
        No *novo = new No(valor);
        No *aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        novo->prox = fim;
        aux->prox = novo;
        n++;
    }

    void imprimir() { // O(n)
        No *aux = inicio;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (tamanho() <= 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No *remover = inicio;
        inicio = inicio->prox;
        delete(remover);
        n--;
    }

    void removerFinal() { // O(n)
        if (tamanho() <= 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No *penultimo = inicio;
        while (penultimo->prox != fim) {
            penultimo = penultimo->prox;
        }
        delete(fim);
        penultimo->prox = NULL;
        fim = penultimo;
        n--;
    }

    void inserir(int valor, int pos) { // O(n)
        if (pos >= tamanho()) {
            inserirFinal(valor);
            return;
        }
        if (pos < 1) {
            inserirInicio(valor);
            return;
        }
        No *aux1 = inicio;
        for (int i = 0; i < pos - 1; i++) {
            aux1 = aux1->prox;
        }
        No *aux2 = aux1->prox;
        No *novo = new No(valor);
        aux1->prox = novo;
        novo->prox = aux2;
        n++;
    }

    void remover(int pos) { // O(n)
        if (pos <= 1) {
            removerInicio();
            return;
        }
        if (pos >= tamanho()) {
            removerFinal();
            return;
        }
        No *aux1 = inicio;
        for (int i = 0; i < pos - 2; i++) {
            aux1 = aux1->prox;
        }
        No *remover = aux1->prox;
        No *aux2 = remover->prox;
        aux1->prox = aux2;
        delete(remover);
        n--;
    }

};

int main() {
    Lista l;

    // Exemplos de uso
    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);
    l.inserir(13, 2);
    l.inserir(0, 0);
    l.inserir(50, 50);

    l.removerUltimosN(2);
    l.removerSegundo();
    l.inserirTamanhoFinal();
    l.inserirAteN(5);
    l.inserirPenultimaPos(99);

    l.imprimir();

    printf("%d\n", l.tamanho());

    return 0;
}
