# Practical-Project-for-Introduction-to-Algorithms

# Intrudução: 

O projeto consiste na criação de um programa de registro de itens (no caso, plantas) com 5
campos definidos pelos alunos, armazenados em arquivos .csv e em arquivos binários. Além
disso, deve ser possível alterar o arquivo de diversas formas por meio da manipulação de um
vetor alocado dinamicamente, inicialmente com 40 posições, que deve ser realocado conforme
o tamanho do arquivo.

# Descrição em Alto Nível das Funções do Programa

• Quick_sortIdentificador: Implementa o algoritmo de ordenação Quick Sort para
ordenar o vetor de plantas pelo campo identificador. A função usa recursão para dividir
o vetor em partes menores, ordenando cada uma até que todo o vetor esteja organizado.
• SalvarDados: Salva os dados das plantas em um arquivo CSV. Para cada planta no
vetor, a função grava seus campos (identificador, nome, região de origem, nome
científico, ano de descobrimento) no arquivo.
• Salvar_registro: Salva um único registro de planta em um arquivo CSV. Essa função
é utilizada para adicionar novos registros ao arquivo sem sobrescrever os existentes.
• ExibirMenu: Exibe o menu principal do programa, mostrando as opções disponíveis
ao usuário, como registrar um novo item, importar/exportar, remover um dado
existente, buscar um elemento, mostrar elementos na tela ou sair do programa.
• ExibirDados: Exibe os dados das plantas armazenadas no vetor. O usuário pode optar
por ver todos os dados ou uma parte específica, escolhendo um intervalo de registros a
serem exibidos.
• CarregarDados: Carrega os dados de plantas de um arquivo CSV para um vetor de
estruturas de Plantas. A função retorna o vetor preenchido e ajusta o tamanho conforme
os dados lidos.
• Quick_sortNome: Implementa o algoritmo de ordenação Quick Sort para ordenar o
vetor de plantas pelo campo nome. Funciona de maneira semelhante à função
quick_sortidentificador, mas utiliza o nome como chave de ordenação.
• RemoverDadoExistente: Remove um registro de planta do arquivo CSV com base no
identificador fornecido pelo usuário. A função cria um arquivo temporário para
armazenar os dados restantes e depois substitui o arquivo original.
• SalvarEmBinario: Salva os dados das plantas em um arquivo binário. Os dados são
copiados de um vetor de Plantas para um vetor de Plantas2 (que usa char para strings)
antes de serem gravados.
• ImportarDadosDeBinario: Importa os dados de um arquivo binário para um vetor de
Plantas. A função lê os dados do arquivo e os converte de volta para a estrutura Plantas.
• Busca_binaria: Implementa uma busca binária para encontrar uma planta pelo nome
no vetor de plantas. Retorna o índice do vetor onde o nome foi encontrado ou -1 se o
nome não existir.
• RegistrarNovoElemento: Permite que o usuário registre um novo elemento (planta)
no vetor e o salve no arquivo CSV. A função expande o vetor original para incluir o
novo registro e então grava todos os registros no arquivo.
• Main: A função principal que inicializa o programa. Ela carrega os dados do arquivo
CSV, exibe o menu principal e chama as funções apropriadas com base na escolha do
usuário. O programa continua a executar até que o usuário escolha sair.
Ordem dos Dados Armazenados
O arquivo .csv "Plantas.csv" contém os dados das plantas conforme a estrutura definida na
struct Plantas. Cada registro de planta no arquivo é composto pelos seguintes campos:
• Identificador: Um inteiro que serve para enumerar as plantas presentes no registro.
• Nome: Uma string com espaços que representa o nome das plantas.
• Região de Origem: Uma string com espaços que representa a região de origem da
planta.
• Nome Científico: Uma string com espaços que representa o nome científico da planta.
• Ano de Descobrimento: Um inteiro que demarca o ano de descobrimento da planta.

# Conclusão

O projeto realizado obteve sucesso ao desenvolver um sistema de registro operacional e
eficiente, capaz de armazenar e manipular uma grande variedade de informações e dados. Este
projeto teve grande importância não apenas para o desenvolvimento das habilidades de
programação, mas também de habilidades sociais e lógicas, como a capacidade de programar
em grupo e a melhor compreensão de algoritmos lógicos, como os de ordenação. Por fim, o
projeto nos aproximou de uma realidade, ainda que distante, do mercado de trabalho, e nos
proporcionou uma experiência nova
