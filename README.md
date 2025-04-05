# 🌿 Gerenciador de Dados

Um sistema em C++ para gerenciamento de dados (no exemplo escolhido, dados botânicos) com suporte a importação/exportação em arquivos CSV e binários. Ideal para aplicações acadêmicas ou como base para sistemas de catalogação.

---

## 🧠 Funcionalidades

- 📋 Cadastro de novas plantas  
- 📥 Importação de dados de arquivos `.csv` ou `.bin`  
- 📤 Exportação de dados para arquivos `.csv` ou `.bin`  
- 🔍 Busca por identificador ou nome da planta  
- ❌ Remoção de plantas cadastradas  
- 📊 Exibição de todos os dados armazenados  
- 📦 Armazenamento dinâmico com alocação manual de memória  

---

## 📁 Estrutura dos Dados

Cada planta é representada pela seguinte estrutura:

```cpp
struct Plantas {
    int identificador;
    string nome;
    string regiaodeorigem;
    string nomecientifico;
    int anodedescobrimento;
};
```

---

## 🚀 Como Executar

### Pré-requisitos

- Compilador C++ (recomendado: `g++`)
- Terminal com suporte a comandos do sistema (`clear` ou `cls`)

### Compilação

```bash
g++ -o gerenciador ProjetoPratico.cpp
```

### Execução

```bash
./gerenciador
```

---

## 🗂️ Arquivos Importantes

- `ProjetoPratico.cpp`: Arquivo principal do projeto  
- `plantas.csv` (exemplo): Arquivo base de dados no formato CSV  
- `dados.bin` (opcional): Arquivo binário com dados exportados  

---

## 📌 Menu de Opções

```text
1. Adicionar nova planta
2. Importar/Exportar dados
3. Remover planta existente
4. Buscar planta (por ID ou Nome)
5. Exibir todas as plantas cadastradas
6. Sair
```

---

## 🔎 Exemplos de Uso

### Cadastro de nova planta

O usuário insere os dados no terminal e o sistema armazena em memória, persistindo no arquivo CSV principal.

### Importação de CSV

Permite importar dados de um arquivo `.csv` externo para o banco de dados principal.

---

## 🧼 Limpeza de Memória

O programa utiliza alocação dinâmica para o vetor de plantas e **garante liberação de memória** ao final de cada iteração do loop principal.

---

## 🛠️ Tecnologias Utilizadas

- Linguagem: **C++**
- Paradigma: Programação Procedural
- Gerenciamento de memória: Alocação dinâmica (`new` e `delete[]`)
- Leitura/Escrita: `fstream`, `ifstream`, `ofstream`
- Ordenação: QuickSort
- Busca: Busca Binária

---

## 🧠 Organização do Código

- Modularizado em funções específicas para:
  - Cadastrar
  - Exibir dados
  - Ordenar
  - Buscar
  - Importar/Exportar
- Menu com repetição controlada por `resetador`
- Interface de terminal limpa com `system("cls||clear")`

---

## 💡 Sugestões Futuras

- Interface gráfica com Qt ou SFML
- Suporte a banco de dados SQLite
- Salvamento automático ao sair
- Filtragem por região ou ano de descoberta

---

## 👨‍💻 Autor

Desenvolvido por **[Diego Oliveira]**, aluno de Ciência da Computação na UFLA.  
Este projeto foi desenvolvido com fins acadêmicos para prática de manipulação de arquivos, alocação dinâmica e busca/ordenação.

---

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo `LICENSE` para mais detalhes.
