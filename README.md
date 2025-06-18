Projeto Heap Sort
📜 Sobre o Projeto
Este projeto consiste na implementação do algoritmo de ordenação Heap Sort. O objetivo é demonstrar o funcionamento do algoritmo, desde a construção da estrutura de dados Max-Heap (ou Min-Heap) até o processo de extração de elementos para obter um array ordenado.

Este código foi desenvolvido como parte de [Mencione o propósito, ex: um trabalho acadêmico da disciplina de Estrutura de Dados, um estudo pessoal, etc.].

🌳 O que é o Heap Sort?
O Heap Sort é um algoritmo de ordenação por comparação, baseado na estrutura de dados de Heap Binário. Ele funciona em duas fases principais:

Construção do Heap: O array desordenado é reorganizado para satisfazer a propriedade de um Max-Heap, onde o valor de cada nó é sempre maior ou igual ao valor de seus filhos. O maior elemento do array estará na raiz do heap.

Extração e Ordenação: O maior elemento (a raiz) é trocado com o último elemento do heap. O heap é então reduzido em um elemento, e a propriedade de Max-Heap é restaurada na raiz. Esse processo é repetido até que o heap esteja vazio, resultando em um array ordenado.

Sua complexidade de tempo é de O(nlogn) em todos os casos (pior, médio e melhor), tornando-o um algoritmo de ordenação muito eficiente.

✨ Detalhes da Implementação
Linguagem: Implementado em [Escreva a linguagem, ex: C++, Python, Java].
Funções Principais:
heapify: Função responsável por transformar um subtree em um Max-Heap.
buildMaxHeap: Constrói o Max-Heap a partir de um array desordenado.
heapSort: Orquestra o processo de ordenação completo.
[Adicione outros detalhes, ex: O programa lê dados de um arquivo? Gera números aleatórios? Imprime cada passo?]
🚀 Tecnologias Utilizadas
[Linguagem de Programação, ex: Python 3.9]
[Qualquer biblioteca ou framework utilizado, ex: Matplotlib para visualização]
⚙️ Como Compilar e Executar
Siga as instruções abaixo para executar o projeto em sua máquina local.

Clone o repositório:

Bash

git clone https://github.com/ikki157/ProjetoHeapSort.git
Navegue até a pasta do projeto:

Bash

cd ProjetoHeapSort
Compile o código (se necessário):

Bash

[Adicione aqui o comando de compilação, ex: gcc -o heapsort main.c]
Execute o programa:

Bash

[Adicione aqui o comando de execução, ex: ./heapsort]
📋 Exemplo de Uso
[Opcional, mas recomendado]

Você pode mostrar um trecho de código de como seu algoritmo é chamado ou qual é a saída esperada do programa.

Exemplo de saída:

Array original: [4, 10, 3, 5, 1, 12, 8]
Array ordenado: [1, 3, 4, 5, 8, 10, 12]
👤 Autor
Ikki Silva Carvalho - www.linkedin.com/in/ikki-silva-carvalho-0639a4323
