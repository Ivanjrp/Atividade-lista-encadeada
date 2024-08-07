Exercício lista encadeada

Funcionalidades:

A lista encadeada possui as seguintes funcionalidades:

1. Criação da lista vazia:
   - A lista é criada vazia e o ponteiro `cabeca` é inicializado para `NULL`.

2. Verificar se a lista está vazia:
   - Método `vazia() const`: Retorna `true` se a lista estiver vazia e `false` caso contrário.

3. Obter o tamanho da lista:
   - Método `getTamanho() const`: Retorna o número de elementos presentes na lista.

4. Obter o valor do elemento de uma determinada posição:
   - Método `getElemento(int posicao) const`: Retorna o valor do elemento na posição especificada. Se a posição for inválida, retorna `-1`.

5. Modificar o valor do elemento de uma determinada posição:
   - Método `altElemento(int posicao, int valor)`: Altera o valor do elemento na posição especificada. Se a posição for inválida, não realiza a alteração.

6. Inserir um elemento em uma determinada posição:
   - Método `inserir(int posicao, int valor)`: Insere um novo elemento na posição especificada. Se a posição for inválida, exibe uma mensagem de erro.

7. Remover um elemento de uma determinada posição:
   - Método `remover(int posicao)`: Remove o elemento da posição especificada e retorna seu valor. Se a posição for inválida, retorna `-1`.

8. Imprimir os elementos de toda a lista:
   - Método `imprimirLista() const`: Imprime todos os elementos da lista, do início ao fim.
