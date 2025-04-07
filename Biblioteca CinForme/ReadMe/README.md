# 📚 Biblioteca CInForme

Projeto em C++ de gerenciamento de uma biblioteca, com funcionalidades de cadastro e autenticação de usuários, controle de livros e operações como aluguel, devolução e edição de livros.

---

## 🛠️ Estrutura do Projeto

### 📁 Arquivos e Funções

#### `ItemBiblioteca.h / ItemBiblioteca.cpp`
- Classe abstrata que representa qualquer item da biblioteca.
- Atributos: `id`, `titulo`, `autor`, `alugado`.
- Método virtual puro: `exibirInformacoes()`.
- Getters/Setters: `getId()`, `getTitulo()`, `getAutor()`, `isAlugado()`, `setTitulo()`, `setAutor()`, `setAlugado()`.

#### `Livro.h / Livro.cpp`
- Herda de `ItemBiblioteca`.
- Representa um livro com dados como título, autor e status de aluguel.
- Métodos:  
  - `Livro(...)` – construtor.  
  - `exibirInformacoes()` – exibe as informações do livro no console.

#### `Usuario.h / Usuario.cpp`
- Representa um usuário do sistema.
- Atributos: nome de usuário, senha e lista de IDs dos livros alugados.
- Métodos:
  - `Usuario(...)` – construtor.  
  - `autenticar(...)` – verifica a senha.  
  - `alugarLivro(...)`, `devolverLivro(...)`, `getLivrosAlugados()`.

#### `Biblioteca.h / Biblioteca.cpp`
- Classe principal que gerencia usuários, livros e controle de acesso.
- Estruturas:
  - Tabela hash para armazenar livros.
  - Vetor de usuários.
  - Ponteiro para o usuário logado.
- Métodos:
  - **Acesso**: `Cadastrar_Usuario()`, `Login()`, `Logout()`.
  - **Ações com livros**: `Adicionar_Livro()`, `Listar_Livros()`, `buscarLivroPorId(id)`, `hash(id)`, `Alugar_Livro()`, `Devolver_Livro()`, `Listar_Livros_Alugados()`, `Editar_Livro()`, `Remover_Livro()`.
  - `MenuBiblioteca()` – menu interativo para o usuário logado.

#### `main.cpp`
- Ponto de entrada da aplicação.
- Loop principal para:
  - Cadastrar usuário.
  - Fazer login.
  - Acessar o `MenuBiblioteca()` após login bem-sucedido.

---

## 🔑 Funcionalidades

- Cadastro e login de usuários.
- Adição, edição, remoção e listagem de livros.
- Aluguel e devolução de livros.
- Visualização de livros alugados.
- Gerenciamento seguro de acesso e permissões.

---

## 👨‍💻 Conceitos de POO Utilizados

- **Herança:** `Livro` herda de `ItemBiblioteca`.
- **Polimorfismo:** método `exibirInformacoes()` é virtual puro e implementado em `Livro`.
- **Encapsulamento:** atributos protegidos/privados com acesso por getters/setters.
- **Classes Abstratas:** `ItemBiblioteca` é abstrata, forçando subclasses a implementar `exibirInformacoes()`.
- **Getters e Setters:** acesso controlado aos dados internos.
- **Tabela Hash:** para armazenamento eficiente de livros via `tabelaLivros[TAMANHO_TABELA]`.

---

## 📌 Tecnologias Utilizadas

- C++17
- STL (`vector`, `string`, `shared_ptr`)
- Programação Orientada a Objetos


## 👤 Autor

Projeto desenvolvido por Carlos Alexandre [cassj]