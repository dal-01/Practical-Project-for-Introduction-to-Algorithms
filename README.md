# projeto-pratico-introducao-algoritmos

## Introdução

O projeto consiste na criação de um programa de registro de itens (no caso, plantas) com 5 campos definidos pelos alunos, armazenados em arquivos `.csv` e em arquivos binários. Além disso, deve ser possível alterar o arquivo de diversas formas por meio da manipulação de um vetor alocado dinamicamente, inicialmente com 40 posições, que deve ser realocado conforme o tamanho do arquivo.

## Descrição em alto nível das funções do programa

- **Quick_sortIdentificador**: Implementa o algoritmo de ordenação Quick Sort para ordenar o vetor de plantas pelo campo identificador. A função usa recursão para dividir o vetor em partes menores, ordenando cada uma até que todo o vetor esteja organizado.
- **SalvarDados**: Salva os dados das plantas em um arquivo CSV. Para cada planta no vetor, a função grava seus campos (identificador, nome, região de origem, nome científico, ano de descobrimento) no arquivo.
- **Salvar_registro**: Salva um único registro de planta em um arquivo CSV. Essa função é utilizada para adicionar novos registros ao arquivo sem sobrescrever os existentes.
- **ExibirMenu**: Exibe o menu principal do programa, mostrando as opções disponíveis ao usuário, como registrar um novo item, importar/exportar, remover um dado existente, buscar um elemento, mostrar elementos na tela ou sair do programa.
- **ExibirDados**: Exibe os dados das plantas armazenadas no vetor. O usuário pode optar por ver todos os dados ou uma parte específica, escolhendo um intervalo de registros a serem exibidos.
- **CarregarDados**: Carrega os dados de plantas de um arquivo CSV para um vetor de estruturas de `Plantas`. A função retorna o vetor preenchido e ajusta o tamanho conforme os dados lidos.


## Conclusão

O projeto realizado obteve sucesso ao desenvolver um sistema de registro operacional e
eficiente, capaz de armazenar e manipular uma grande variedade de informações e dados. Este
projeto teve grande importância não apenas para o desenvolvimento das habilidades de
programação, mas também de habilidades sociais e lógicas, como a capacidade de programar
em grupo e a melhor compreensão de algoritmos lógicos, como os de ordenação. Por fim, o
projeto nos aproximou de uma realidade, ainda que distante, do mercado de trabalho, e nos
proporcionou uma experiência nova.
