/*
Projeto Prático de Introdução aos Algoritmos 2024

GRUPO:
Gustavo Martins de Oliveira (202411213)
Diego Alves de Oliveira (202410370)

TEMA:
Plantas

CAMPOS:
Identificador (inteiro)
Nome (string com espaços)
Região de origem (string com espaços)
Nome científico (string com espaços)
Ano de descobrimento (inteiro curto)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const string nome_arquivo = "plantas.csv"; //constante que é usada em praticamente todas a funções

struct Plantas { //struct com os campos
    int identificador;
    string nome;
    string regiaodeorigem;
    string nomecientifico;
    short anodedescobrimento;
};
struct Plantas2 { //struct com char ao invês de string para os arquivos binários
    int identificador;
    char nome[50];
    char regiaodeorigem[50];
    char nomecientifico[50];
    short anodedescobrimento;
};

void quick_sortidentificador( Plantas* vetorPlantas, int inicio, int fim){ //função que ordena o vetor para permitir a busca binária pelo identificador escolhido pelo usuário

    int pivo, esq, dir, meio, aux2;
    string aux;
    //limites da esquerda e direita da região analisada
    esq = inicio;
    dir = fim;

    //ajustando auxiliares do centro
    meio =  int(((esq + dir) / 2));
    pivo = vetorPlantas[meio].identificador;


    while(dir > esq){

        while(vetorPlantas[esq].identificador < pivo){
            esq = esq + 1;
        }

        while(vetorPlantas[dir].identificador > pivo){
            dir = dir - 1;
        }

        if(esq <= dir){

            //realiza as trocas de posição
            aux = vetorPlantas[esq].nome;
            vetorPlantas[esq].nome = vetorPlantas[dir].nome;
            vetorPlantas[dir].nome = aux;
            aux2 = vetorPlantas[esq].identificador;
            vetorPlantas[esq].identificador = vetorPlantas[dir].identificador;
            vetorPlantas[dir].identificador = aux2;
            aux = vetorPlantas[esq].nomecientifico;
            vetorPlantas[esq].nomecientifico = vetorPlantas[dir].nomecientifico;
            vetorPlantas[dir].nomecientifico = aux;
            aux = vetorPlantas[esq].regiaodeorigem;
            vetorPlantas[esq].regiaodeorigem = vetorPlantas[dir].regiaodeorigem;
            vetorPlantas[dir].regiaodeorigem = aux;
            aux2 = vetorPlantas[esq].anodedescobrimento;
            vetorPlantas[esq].anodedescobrimento = vetorPlantas[dir].anodedescobrimento;
            vetorPlantas[dir].anodedescobrimento = aux2;

            //faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;

        }

    }

    //recursão para continuar ordenando
    if(inicio < dir){
        quick_sortidentificador(vetorPlantas,inicio,dir);
    }

     //recursão para continuar ordenando
    if(esq < fim){
         quick_sortidentificador(vetorPlantas, esq, fim);
    }

}

void SalvarDados(const string& nome_arquivo, Plantas* vetorPlantas, int tamanho){ //função usada para gravar as informações pegas dentro do arquivo binário e colocá-las no arquivo principal
    ofstream arquivo(nome_arquivo, ios_base::app); //abre o arquivo para escrita sem excluir o que já está gravado
    for (int i = 0; i < tamanho; i++) {
        arquivo << vetorPlantas[i].identificador << "," << vetorPlantas[i].nome << ","
                << vetorPlantas[i].regiaodeorigem << "," << vetorPlantas[i].nomecientifico << ","
                << vetorPlantas[i].anodedescobrimento << endl;
    }
    arquivo.close();
}

void exibirMenu() { //função que faz surgir o menu principal

    cout << "*" << "--------------------------------------"<< "*" << endl;
    cout << "|" << "                                      " << "|" << endl;
    cout << "| " << "      " << "Registrador de Plantas" << "        " << " |" << endl;
    cout << "|" << "                                      " << "|" << endl;
    cout << "| 1. Registrar novo item" << "              " << " |" << endl;
    cout << "| 2. Importar/exportar" << "                " << " |" << endl;
    cout << "| 3. Remover dado existente" << "           " << " |" << endl;
    cout << "| 4. Buscar elemento" << "                  " << " |" << endl;
    cout << "| 5. Mostrar elementos na tela" << "        " << " |" << endl;
    cout << "| 6. Sair" << "                             " << " |" << endl;
    cout << "*" << "--------------------------------------"<< "*" << endl;
}

void exibirDados(Plantas* vetorPlantas, int tamanho) { //função para exibir os dados dentro do vetor/arquivo
    int aux1 = 0;
    int aux2 = 0;
    int aux3 = 0;
    int retomar = 1;
    while(retomar == 1){
    cout << "Deseja exibir o arquivo inteiro ou uma parte fracionada?" << endl;
    cout << "1.Inteiro" << endl;
    cout << "2.Fracionado" << endl;
    cin >> aux1;
    if (aux1 == 1){
    system("cls||clear");
    for (int i = 0; i < tamanho; i++) { //mostra todos os campos de todos os elementos
        cout << "Identificador: " << vetorPlantas[i].identificador << endl;
        cout << "Nome: " << vetorPlantas[i].nome << endl;
        cout << "Regiao de Origem: " << vetorPlantas[i].regiaodeorigem << endl;
        cout << "Nome Cientifico: " << vetorPlantas[i].nomecientifico << endl;
        cout << "Ano de Descobrimento: " << vetorPlantas[i].anodedescobrimento << endl;
        cout << "---------------------------------" << endl;
    }
    retomar  = -1;
    }
    else if (aux1 == 2){
        retomar  = -1;
        int a = 2;
        int b = 1;
        system("cls||clear");
        while(a == 2){
        cout << "A partir de qual posicao voce deseja mostrar?" << endl;
        cin >> aux2;
            if (aux2 < 1){
            system("cls||clear");
            cout << "Opcao invalida" << endl;
        }
        else if(aux2 > tamanho){
            system("cls||clear");
            cout << "Esse registro so tem "<< tamanho << " elementos" << endl;
        }
        else{
            system("cls||clear");
            a = -1;
        }
        }

        while(b==1){
        cout << "Em qual posicao voce deseja parar?" << endl;
        cin >> aux3;
         if (aux3 < 1){
            system("cls||clear");
            cout << "Opcao invalida" << endl;
        }
        else if(aux3 > tamanho){ //se o numero digitado for maior que o número de elementos presentes
            system("cls||clear");
            cout << "Esse registro so tem "<< tamanho << " elementos" << endl;
        }
        else{
            system("cls||clear");
            b = -1;
        }
        }
        if(aux2 > aux3){ //se o primeiro número digitado for maior que o segundo ocorre uma troca
            int aux4;
            aux4 = aux2;
            aux2 = aux3;
            aux3 = aux4;

        }
        system("cls||clear");
        aux2--;
        while (aux2<aux3){ //mostra todos os elementos dos elementos selecionados
        cout << "Identificador: " << vetorPlantas[aux2].identificador << endl;
        cout << "Nome: " << vetorPlantas[aux2].nome << endl;
        cout << "Regiao de Origem: " << vetorPlantas[aux2].regiaodeorigem << endl;
        cout << "Nome Cientifico: " << vetorPlantas[aux2].nomecientifico << endl;
        cout << "Ano de Descobrimento: " << vetorPlantas[aux2].anodedescobrimento << endl;
        cout << "---------------------------------" << endl;
        aux2++;
        }
        }
    else    {
        system("cls||clear");
        cout << "Opcao invalida" << endl;


        }
    }
    }

Plantas* carregarDados(const string& nome_arquivo, int& tamanho) { //função para carregar os cados do arquivo e colocar dentro do vetor
    ifstream arquivo(nome_arquivo); // abre o arquivo pra leitura

    int capacidade = 40; // Tamanho inicial do vetor
    Plantas* vetorPlantas = new Plantas[capacidade]; // aloca o vetor dinamicamente com 40 espaços
    tamanho = 0;

    string linha;
    getline(arquivo, linha);// Ignora a linha de cabeçalho
    linha.erase(); //limpa a variável linha

    // Lê os dados do arquivo linha por linha e realoca o vetor caso o tamanho do arquivo passe a capacidade do vetor
    while (getline(arquivo, linha)) { //pega as informações e grava em linha enquanto o arquivo está aberto
        if (tamanho == capacidade) {
            // Aumenta a capacidade do vetor em 10
            capacidade += 10;
            Plantas* novoVetorPlantas = new Plantas[capacidade];
            // Copia os dados para o novo vetor
            for (int i =  0; i < tamanho; i++) {
                novoVetorPlantas[i] = vetorPlantas[i];
            }

            delete[] vetorPlantas; // Libera o espaço do vetor antigo
            vetorPlantas = novoVetorPlantas; //O vetor antigo recebe o novo para continuar as inserções
        }

        int pos = 0;

        // Identificador
        pos = linha.find(','); //acha a posição da vírgula na variável linha
        vetorPlantas[tamanho].identificador = stoi(linha.substr(0,pos)); // coloca dentro do vetor tudo que está entre e a posição da virgula e usa função STOI para converter isso para inteiro
        linha.erase(0, pos + 1); //limpa a variavel linha para poder ser usada denovo

        // Nome
        pos = linha.find(',');
        vetorPlantas[tamanho].nome = linha.substr(0, pos);
        linha.erase(0, pos + 1);

        // Região de origem
        pos = linha.find(',');
        vetorPlantas[tamanho].regiaodeorigem = linha.substr(0, pos);
        linha.erase(0, pos + 1);

        // Nome científico
        pos = linha.find(',');
        vetorPlantas[tamanho].nomecientifico = linha.substr(0, pos);
        linha.erase(0, pos + 1);

        // Ano de descobrimento
        vetorPlantas[tamanho].anodedescobrimento = stoi(linha);//não precisa da posição pois depois vem a quebra de linha e o ciclo se repete
        tamanho++; //aumenta o contador do tamanho do arquivo
    }
    return vetorPlantas;
}

void quick_sortnome( Plantas* vetorPlantas, int inicio, int fim){ //função para ordenação do vetor com base no nome para possibilidar busca binária
    int esq, dir, meio;
    string aux,pivo;
    int aux2;
    //Limites da esquerda e direita da região analisada
    esq = inicio;
    dir = fim;

    //Ajustando auxiliares do centro
    meio =  int(((esq + dir) / 2));
    pivo = vetorPlantas[meio].nome;


    while(dir > esq){

        while(vetorPlantas[esq].nome < pivo){
            esq = esq + 1;
        }

        while(vetorPlantas[dir].nome > pivo){
            dir = dir - 1;
        }

        if(esq <= dir){

            //Realiza uma troca
            aux = vetorPlantas[esq].nome;
            vetorPlantas[esq].nome = vetorPlantas[dir].nome;
            vetorPlantas[dir].nome = aux;
            aux2 = vetorPlantas[esq].identificador;
            vetorPlantas[esq].identificador = vetorPlantas[dir].identificador;
            vetorPlantas[dir].identificador = aux2;
            aux = vetorPlantas[esq].nomecientifico;
            vetorPlantas[esq].nomecientifico = vetorPlantas[dir].nomecientifico;
            vetorPlantas[dir].nomecientifico = aux;
            aux = vetorPlantas[esq].regiaodeorigem;
            vetorPlantas[esq].regiaodeorigem = vetorPlantas[dir].regiaodeorigem;
            vetorPlantas[dir].regiaodeorigem = aux;
            aux2 = vetorPlantas[esq].anodedescobrimento;
            vetorPlantas[esq].anodedescobrimento = vetorPlantas[dir].anodedescobrimento;
            vetorPlantas[dir].anodedescobrimento = aux2;

            //Faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;

        }

    }

    //Recursão para continuar ordenando
    if(inicio < dir){
        quick_sortnome(vetorPlantas,inicio,dir);
    }

     //Recursão para continuar ordenando
    if(esq < fim){
         quick_sortnome(vetorPlantas, esq, fim);
    }
}

void removerDadoExistente() { //função que remove o elemento escolhido pelo usuário

    int identificador;
    cout << "Digite o identificador da planta que voce deseja remover: ";
    cin >> identificador; //usuário decide qual o identificador do elemento que ele quer excluir
    ifstream arquivo(nome_arquivo);//abre o arquivo principal para leitura
    ofstream temp("temp.csv");//cria um arquivo temporário .csv
    string linha;
    bool encontrado = false; //bool para ver se o elemento foi encontrado


    getline(arquivo, linha); // Copia a linha de cabeçalho para o arquivo temporário
    temp << linha << endl;
    linha.erase();

    while (getline(arquivo, linha)) {
        int pos = linha.find(','); //acha a posição da vírgula na variável linha
        if (stoi(linha.substr(0, pos)) != identificador) { // passa todos os elementos com identificador diferente do escolhido pelo usuário para o arquivo temporário
            temp << linha << endl;
        } else {
            encontrado = true;
        }
    }

    arquivo.close(); //fecha o arquivo principal
    temp.close(); //fecha o arquivo temporário

    remove(nome_arquivo.c_str()); //remove o arquivo principal
    rename("temp.csv", nome_arquivo.c_str()); //renomeia o arquivo temporario(sem o elemento que o usuário escolheu) para o nome do arquivo principal

    if (encontrado) { //se não for encontrado nenhum elemento com o identificador digitado
        cout << "Elemento removido com sucesso!" << endl;
    } else {
        cout << "Elemento nao encontrado." << endl;
    }
}

void salvarEmBinario(const string& nome_arquivo, Plantas* vetorPlantas, int tamanho) { //função que exporta os dados do arquivo principal para um arquivo binário
    if (tamanho <= 0) { //se não existir nada no arquivo principal
        cout << "Nao ha dados suficientes para salvar." << endl;
        return;
    }

    // Alocar um novo vetor na outra struct de char
    Plantas2* vetorPlantas2 = new Plantas2[tamanho];

    // Copiar os dados do vetor principal para o vetor secundário
    for (int i = 0; i < tamanho; i++) {
        vetorPlantas2[i].identificador = vetorPlantas[i].identificador;


        strncpy(vetorPlantas2[i].nome, vetorPlantas[i].nome.c_str(), sizeof(vetorPlantas2[i].nome));//função strncpy é usada para copiar os dados de string e .c_str() para o ponteiro para a string

        strncpy(vetorPlantas2[i].nomecientifico, vetorPlantas[i].nomecientifico.c_str(), sizeof(vetorPlantas2[i].nomecientifico));


        strncpy(vetorPlantas2[i].regiaodeorigem, vetorPlantas[i].regiaodeorigem.c_str(), sizeof(vetorPlantas2[i].regiaodeorigem));


        vetorPlantas2[i].anodedescobrimento = vetorPlantas[i].anodedescobrimento;
    }

    ofstream arqBinary(nome_arquivo, ios::binary);  // Abrir arquivo binário para escrita
    if (!arqBinary) { //se o arquivo não existir
        cout << "Erro ao abrir o arquivo " << nome_arquivo << " para escrita." << endl;
        delete[] vetorPlantas2; // Liberar memória
        return;
    }


    arqBinary.write((const char*)(vetorPlantas2), sizeof(Plantas2) * tamanho); // Escrever os dados no arquivo binário
    arqBinary.close();


    delete[] vetorPlantas2; // Liberar memória do vetor secundário
    cout << "Dados salvos com sucesso no arquivo binario " << nome_arquivo << "!" << endl;
}

Plantas* importarDadosDeBinario(const string& nome_arquivo, int& tamanho) { //função que permite o programa importar dados de um arquivo binário a escolha do usuário
    ifstream arquivo(nome_arquivo, ios::binary); //abre o arquivo binário para leitura

    if (!arquivo) { //se o arquivo não existir
        cout << "Erro ao abrir o arquivo " << nome_arquivo << " para leitura." << endl;
        tamanho = 0;
    }


    arquivo.seekg(0, ios::end);  // Move o ponteiro de leitura para o final do arquivo para determinar o tamanho total do arquivo em bytes com a função tellg()
    streampos fileSize = arquivo.tellg();
    arquivo.seekg(0, ios::beg); // reposiciona para o começo denovo


    tamanho = fileSize / sizeof(Plantas2);  // calcula o número de elementos no arquivo


    Plantas2* vetorPlantas2 = new Plantas2[tamanho]; //aloca um novo vetor do tamanho do arquivo


    arquivo.read(reinterpret_cast<char*>(vetorPlantas2), sizeof(Plantas2) * tamanho); // lê os dados do vetor do arquivo binário


    Plantas* vetorPlantas = new Plantas[tamanho]; //aloca um novo vetor para fazer a conversão de char(utilizados para ler) para string (struct principal)
    for (int i = 0; i < tamanho; i++) { //armazena fazendo a conversão
        vetorPlantas[i].identificador = vetorPlantas2[i].identificador;
        vetorPlantas[i].nome = string(vetorPlantas2[i].nome);
        vetorPlantas[i].nomecientifico = string(vetorPlantas2[i].nomecientifico);
        vetorPlantas[i].regiaodeorigem = string(vetorPlantas2[i].regiaodeorigem);
        vetorPlantas[i].anodedescobrimento = vetorPlantas2[i].anodedescobrimento;
    }


    delete[] vetorPlantas2;

    arquivo.close();
    return vetorPlantas; //retorna o vetor com os dados do arquivo binário
}

int buscaBinaria(Plantas* vetorPlantas, int tamanho, string procurado){ // função que faz a busca binária de acordo com o nome escolhido pelo usuário
 int inicio = 0;
 int fim = (tamanho - 1);
 int meio = (inicio + fim)/2;

 while(inicio<=fim){
    if(procurado == vetorPlantas[meio].nome){
        return meio;
    }
    else if (procurado > vetorPlantas[meio].nome){
        inicio = (meio +1);
        meio = (inicio + fim)/2;
    }
    else if (procurado < vetorPlantas[meio].nome){
        fim = (meio-1);
        meio = (inicio + fim)/2;
    }
 }
return -1;
}

void registrarNovoElemento(Plantas* vetorPlantas, int& tamanho){ //função que faz a adição do elemento registrado pelo usuário no arquivo
  int a,e;
  string b,c,d;
  int tamanho2 = tamanho + 1;
    Plantas* novovetorplantas = new Plantas[tamanho2]; //faz a realocação de um elemento
  for (int i = 0;i < tamanho;i++){
    novovetorplantas[i].identificador = vetorPlantas[i].identificador;
    novovetorplantas[i].nome = vetorPlantas[i].nome;
    novovetorplantas[i].regiaodeorigem = vetorPlantas[i].regiaodeorigem;
    novovetorplantas[i].nomecientifico = vetorPlantas[i].nomecientifico;
    novovetorplantas[i].anodedescobrimento = vetorPlantas[i].anodedescobrimento;
  }
        cout << "Digite o identificador da planta: "; //usuário digita os componentes do elemento
                cin >> a;
                cin.ignore();
                cout << "Digite o nome da planta: ";
                getline(cin, b);
                cout << "Digite a regiao de origem da planta: ";
                getline(cin, c);
                cout << "Digite o nome cientifico da planta: ";
                getline(cin, d);
                cout << "Digite o ano de descobrimento da planta: ";
                cin >> e;
                cin.ignore();

                novovetorplantas[tamanho].identificador = a;
                novovetorplantas[tamanho].nome = b;
                novovetorplantas[tamanho].regiaodeorigem = c;
                novovetorplantas[tamanho].nomecientifico = d;
                novovetorplantas[tamanho].anodedescobrimento = e;

                ofstream arquivo(nome_arquivo); //escreve o vetor realocado no arquivo principal
    arquivo << "Identificador,Nome,Regiao de origem,Nome cientifico,Ano de descobrimento" << endl;
    for (int i = 0; i < tamanho2; i++) {
        arquivo << novovetorplantas[i].identificador << "," << novovetorplantas[i].nome << ","
                << novovetorplantas[i].regiaodeorigem << "," << novovetorplantas[i].nomecientifico << ","
                << novovetorplantas[i].anodedescobrimento << endl;
    }
    arquivo.close();
}


int main() {
    int resetador = 1;
    int tamanho = 1;
    while(resetador == 1){ //programa sempre retornará para o menu a não ser que o usuário deseje sair
    Plantas* vetorPlantas = carregarDados(nome_arquivo, tamanho);// Carrega os dados do arquivo para o vetor alocado dinamicamente
    int opcao;
    exibirMenu();
    cout << "Digite o numero da opcao: ";
    cin >> opcao; //usuário escolhe o que ele quer fazer no programa

    switch (opcao) {
        case 1:{
            


        
            system("cls||clear");
                int aux;
                
                registrarNovoElemento(vetorPlantas,tamanho);

                cout << "Deseja voltar ao menu principal? "<< endl;
                cout << "1.Sim" <<endl;
                cout << "2.Nao" <<endl;
                cin >> aux;
                if (aux == 1){
                    system("cls||clear");
                    cout << "Elemento adicionado com sucesso" << endl;
                    break;
                }
                else {
                    system("cls||clear");
                    resetador = -1;
                    break;
                }
        }

        case 2: {
            int aux3;
            int a, b,c;
            b = 1;
            int cont = 0;
            string aux1;
            system("cls||clear");
            while (b == 1){
            cout << "Deseja Importar ou Exportar?" << endl;
            cout << "1. Importar" << endl;
            cout << "2. Exportar" << endl;
            cin >> a;
            if (a == 1) {
                b = -1;
            cout << "Deseja importar de um arquivo binario ou csv?" << endl;
            cout << "1. Binario" << endl;
            cout << "2. CSV" << endl;
            cin >> c;
            if (c == 2){
                cout << "Qual o nome do arquivo que voce deseja importar dados?" << endl;
                cin >> aux1;

                ifstream arquivo(aux1); //abre o arquivo de novo digitado pelo usuário para leitura
                if (!arquivo.good()) { // se o arquivo não existir
                        system("cls||clear");
                        cout << "Arquivo invalido" << endl;
                        break;
                 }
    //mesmo código de realocação da função CarregarDados
    int capacidade = 40;
    Plantas* vetorinportar = new Plantas[capacidade];
    int tamanho2 = 0;

    string linha;
     getline(arquivo, linha);

    while (getline(arquivo, linha)) {
            cont++;
        if (tamanho2 == capacidade) {

            capacidade += 10;
            Plantas* vetorinportar2 = new Plantas[capacidade];

            for (int i = 0; i < tamanho2; i++) {
                vetorinportar2[i] = vetorinportar[i];
            }

            delete[] vetorinportar;
            vetorinportar = vetorinportar2;
        }

        int pos = 0;


        pos = linha.find(',');
        vetorinportar[tamanho2].identificador =  stoi(linha.substr(0, pos)); // stoi usado para converter string para inteiro
        linha.erase(0, pos + 1);


        pos = linha.find(',');
        vetorinportar[tamanho2].nome = linha.substr(0, pos);
        linha.erase(0, pos + 1);


        pos = linha.find(',');
        vetorinportar[tamanho2].regiaodeorigem = linha.substr(0, pos);
        linha.erase(0, pos + 1);


        pos = linha.find(',');
        vetorinportar[tamanho2].nomecientifico = linha.substr(0, pos);
        linha.erase(0, pos + 1);


        vetorinportar[tamanho2].anodedescobrimento = stoi(linha);

        tamanho2++;
    }
    arquivo.close();
   ofstream saida(nome_arquivo, ios_base::app); //escreve os elementos do arquivo escolhido pelo usuário para o principal
   saida << endl;
   for (int i = 0; i<cont;i++){
   saida       << vetorinportar[i].identificador << ","
                            << vetorinportar[i].nome << ","
                            << vetorinportar[i].regiaodeorigem << ","
                            << vetorinportar[i].nomecientifico << ","
                            << vetorinportar[i].anodedescobrimento << "\n";
   }
    saida.close();
    system("cls||clear");
    cout << "Elementos importados com sucesso do arquivo " << aux1 << "!" << endl;
    cout << "Deseja voltar ao Menu Principal?" << endl;
        cout << "1.Sim" << endl;
        cout << "2.Nao" << endl;
        cin >> aux3;
        if (aux3 == 1){
            system("cls||clear");
            break;
        }
        else{
            system("cls||clear");
            resetador = -1;
            break;
        }
            }
            else if (c == 1){
            string nomeArquivoBinario;
            cout << "Digite o nome do arquivo binario para importar: " << endl;
            cin >> nomeArquivoBinario;

            int tamanho;
            Plantas* vetorPlantasImportados = importarDadosDeBinario(nomeArquivoBinario,tamanho); //funçao retorna vetor dos dados do arquivo binário
            SalvarDados(nome_arquivo,vetorPlantasImportados,tamanho);//Salva os dados do arquivo binário(agora no vetorImportados) no arquivo principal
            int aux4;
            system("cls||clear");
            cout << "Elementos importados com sucesso do arquivo " << nomeArquivoBinario << "!" << endl;
            cout << "Deseja voltar ao Menu Principal?" << endl;
            cout << "1.Sim" << endl;
            cout << "2.Nao" << endl;
            cin >> aux4;
        if (aux4 == 1){
            system("cls||clear");
            break;
        }
        else{
            system("cls||clear");
            resetador = -1;
            break;
        }
            }
            }
             else if (a == 2) {
                int aux2;
                b = -1;
                cout << "Deseja exportar para um arquivo binario ou csv?" << endl;
                cout << "1.Binario" << endl;
                cout << "2.CSV" << endl;
                cin >> aux2;
                if(aux2 == 2){
                cout << "Qual o nome do arquivo que voce deseja exportar os dados?" << endl;
                cin >> aux1;
               ofstream saida(aux1, ios_base::app); //Abre para escrita ou cria um arquivo e exporta os dados do vetor principal para ele
   for (int i = 0; i<tamanho;i++){
   saida       << vetorPlantas[i].identificador << ","
                            << vetorPlantas[i].nome << ","
                            << vetorPlantas[i].regiaodeorigem << ","
                            << vetorPlantas[i].nomecientifico << ","
                            << vetorPlantas[i].anodedescobrimento << "\n";
   }
    saida.close();
    system("cls||clear");
    cout << "Elementos exportados com sucesso para o arquivo " << aux1 << "!" << endl;
    cout << "Deseja voltar ao Menu Principal?" << endl;
        cout << "1.Sim" << endl;
        cout << "2.Nao" << endl;
        cin >> aux3;
        if (aux3 == 1){
            system("cls||clear");
        }
        else{
            system("cls||clear");
            resetador = -1;

        }
            }
            else if (aux2 == 1){
               cout << "Digite o nome do arquivo binario para exportar: " << endl;;
                        cin >> aux1;
                        salvarEmBinario(aux1, vetorPlantas, tamanho);//Abre para escrita ou cria um arquivo binário e exporta os dados do vetor principal para ele
    cout << "Deseja voltar ao Menu Principal?" << endl;
        cout << "1.Sim" << endl;
        cout << "2.Nao" << endl;
        cin >> aux3;
        if (aux3 == 1){
            system("cls||clear");
        }
        else{
            system("cls||clear");
            resetador = -1;

        }
            }
            else {
                system("cls||clear");
                cout << "Opcao invalida" << endl;
            }
            }

            }
            break;
        }



        case 3:{
            int aux3;
            system("cls||clear");
            removerDadoExistente();
             cout << "Deseja voltar ao Menu Principal?" << endl;
        cout << "1.Sim" << endl;
        cout << "2.Nao" << endl;
        cin >> aux3;
        if (aux3 == 1){
            system("cls||clear");
        }
        else{
            system("cls||clear");
            resetador = -1;

        }
         break;
            }

        case 4:{
            system("cls||clear");
            int aux1,aux3, a;
            int aux2 = 1;
            cout << "Deseja procurar por qual parametro?" << endl;
            cout << "1.Identificador" << endl;
            cout << "2.Nome" << endl;
            cin >> a;
            if (a == 1){
            while (aux2 == 1){
            cout << "Qual o identificador do elemento que deseja buscar?"<< endl;
            quick_sortidentificador(vetorPlantas,0,tamanho-1); //reorganiza o vetor por indentificador
            cin >> aux1;
            int posicao = -1;
            int posicao_inicial = 0;
            int posicao_final = tamanho - 1;
            int meio;
            while (posicao_inicial <= posicao_final) {
                meio = (posicao_inicial + posicao_final)/2;
                if (aux1 == vetorPlantas[meio].identificador){
                    posicao = meio;
                    posicao_inicial = posicao_final + 1; // parar while
    } else {
         if (aux1 > vetorPlantas[meio].identificador) posicao_inicial = meio + 1;
         else posicao_final = meio - 1;
    }
   }
   if(posicao == -1){ //caso o elemento não seja encontrado
    system("cls||clear");
    cout << "Elemento nao encontrado" << endl;
   }

   else{ //mostra o elemento na tela caso ele seja encontrado
        aux2 = -1;
        cout << "O elemento encontrado foi:" << endl;
        cout << "---------------------------------" << endl;
        cout << "Identificador: " << vetorPlantas[posicao].identificador << endl;
        cout << "Nome: " << vetorPlantas[posicao].nome << endl;
        cout << "Regiao de Origem: " << vetorPlantas[posicao].regiaodeorigem << endl;
        cout << "Nome Cientifico: " << vetorPlantas[posicao].nomecientifico << endl;
        cout << "Ano de Descobrimento: " << vetorPlantas[posicao].anodedescobrimento << endl;
        cout << "---------------------------------" << endl;
        cout << "Deseja voltar ao Menu Principal?" << endl;
        cout << "1.Sim" << endl;
        cout << "2.Nao" << endl;
        cin >> aux3;
        if (aux3 == 1){
            system("cls||clear");
        }
        else{
            system("cls||clear");
            resetador = -1;
        }
   }
            }
            }
            else if(a == 2){
            quick_sortnome(vetorPlantas,0,tamanho-1); //organiza o vetor em ordem alfabética para fazer busca binária pelo nome
            string nome;
            while (aux2 == 1){
            cout << "Qual o nome do elemento que deseja buscar?" << endl;
            cin.ignore();
            getline(cin,nome);
            int posicao;
            posicao = buscaBinaria(vetorPlantas,tamanho,nome); //faz a busca binária pelo nome
            if(posicao == -1){ //se não for encontrado
                system("cls||clear");
                cout << "Elemento nao encontrado" << endl;
   }

   else{ //mostra na tela caso seja encontrado
        aux2 = -1;
        cout << "O elemento encontrado foi:" << endl;
        cout << "---------------------------------" << endl;
        cout << "Identificador: " << vetorPlantas[posicao].identificador << endl;
        cout << "Nome: " << vetorPlantas[posicao].nome << endl;
        cout << "Regiao de Origem: " << vetorPlantas[posicao].regiaodeorigem << endl;
        cout << "Nome Cientifico: " << vetorPlantas[posicao].nomecientifico << endl;
        cout << "Ano de Descobrimento: " << vetorPlantas[posicao].anodedescobrimento << endl;
        cout << "---------------------------------" << endl;
        cout << "Deseja voltar ao Menu Principal?" << endl;
        cout << "1.Sim" << endl;
        cout << "2.Nao" << endl;
        cin >> aux3;
        if (aux3 == 1){
            system("cls||clear");
        }
        else{
            system("cls||clear");
            resetador = -1;
        }
   }

            }
        }
         break;
        }
        case 5:{
            int aux1;
            system("cls||clear");
            quick_sortidentificador(vetorPlantas,0,tamanho-1);//reorganiza os dados de acordo com o identificador
            exibirDados(vetorPlantas, tamanho); //chama a função para mostrar os dados
            cout << "Deseja voltar ao Menu Principal?" << endl;
            cout << "1.Sim" << endl;
            cout << "2.Nao" << endl;
            cin >> aux1;
                if (aux1 == 1){
                    system("cls||clear");
                        break;
    }
                else{
                    system("cls||clear");
                    resetador = -1;
    }
            break;
        }
        case 6:{ //caso a pessoa deseje sair
            resetador = -1;
            break;
        }
        default:{ //caso digite um opção inválida
            system("cls||clear");
            cout << "Opcao invalida. Tente novamente" << endl;
            break;
        }
    }
     delete[] vetorPlantas; //libera a memória alocada no vetor principal
    }
    return 0;
}