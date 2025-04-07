#include "Biblioteca.h"
#include <iostream>
using namespace std;

// Funcao hash para indexar livros
int Biblioteca::hash(int id) {
    return id % TAMANHO_TABELA;
}

// Busca livro pelo ID na tabela
shared_ptr<ItemBiblioteca> Biblioteca::buscarLivroPorId(int id) {
    int indice = hash(id);
    for (auto& livro : tabelaLivros[indice]) {
        if (livro->getId() == id)
            return livro;
    }
    return nullptr;
}

// Funcoes gerais da Biblioteca
// Cadastrar
void Biblioteca::Cadastrar_Usuario() {
    string nome, senha;
    cout << "Novo nome de usuário: ";
    cin >> nome;
    cout << "Senha: ";
    cin >> senha;

    usuarios.emplace_back(nome, senha);
    cout << "Usuário cadastrado com sucesso!\n";
}
//Login
void Biblioteca::Login() {
    string nome, senha;
    cout << "Nome de usuário: ";
    cin >> nome;
    cout << "Senha: ";
    cin >> senha;

    for (auto& u : usuarios) {
        if (u.getNomeUsuario() == nome && u.autenticar(senha)) {
            usuarioLogado = &u;
            cout << "Login realizado com sucesso!\n";
            MenuBiblioteca();
            return;
        }
    }
    cout << "Usuário ou senha inválidos.\n";
}
// Logout
void Biblioteca::Logout() {
    usuarioLogado = nullptr;
    cout << "Logout realizado.\n";
}
// Adicionar
void Biblioteca::Adicionar_Livro() {
    string titulo, autor;
    cout << "Digite o título do livro: ";
    getline(cin >> ws, titulo);
    cout << "Digite o autor do livro: ";
    getline(cin >> ws, autor);

    auto livro = make_shared<Livro>(proximoId, titulo, autor);
    int indice = hash(proximoId);
    tabelaLivros[indice].push_back(livro);
    cout << "Livro adicionado com sucesso!\n";
    proximoId++;
}

void Biblioteca::Listar_Livros() {
    cout << "\n--- Livros Disponíveis ---\n";
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        for (const auto& livro : tabelaLivros[i]) {
            if (!livro->isAlugado())
                livro->exibirInformacoes();
        }
    }
}

void Biblioteca::Alugar_Livro() {
    if (!usuarioLogado) {
        cout << "Você precisa estar logado para alugar um livro.\n";
        return;
    }

    int id;
    cout << "Digite o ID do livro que deseja alugar: ";
    cin >> id;

    auto livro = buscarLivroPorId(id);
    if (livro && !livro->isAlugado()) {
        livro->setAlugado(true);
        usuarioLogado->alugarLivro(id);
        cout << "Livro alugado com sucesso!\n";
    } else {
        cout << "Livro não encontrado ou já está alugado.\n";
    }
}
// Listar
void Biblioteca::Listar_Livros_Alugados() {
    if (!usuarioLogado) {
        cout << "Você precisa estar logado para ver seus livros alugados.\n";
        return;
    }

    cout << "\n--- Seus Livros Alugados ---\n";
    for (int id : usuarioLogado->getLivrosAlugados()) {
        auto livro = buscarLivroPorId(id);
        if (livro)
            livro->exibirInformacoes();
    }
}
// Editar
void Biblioteca::Editar_Livro() {
    int id;
    cout << "Digite o ID do livro que deseja editar: ";
    cin >> id;

    auto livro = buscarLivroPorId(id);
    if (livro) {
        string novoTitulo, novoAutor;
        cout << "Novo título: ";
        getline(cin >> ws, novoTitulo);
        cout << "Novo autor: ";
        getline(cin >> ws, novoAutor);
        livro->setTitulo(novoTitulo);
        livro->setAutor(novoAutor);
        cout << "Livro editado com sucesso!\n";
    } else {
        cout << "Livro não encontrado.\n";
    }
}
// Remover
void Biblioteca::Remover_Livro() {
    int id;
    cout << "Digite o ID do livro que deseja remover: ";
    cin >> id;

    int indice = hash(id);
    auto& lista = tabelaLivros[indice];
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        if ((*it)->getId() == id) {
            if ((*it)->isAlugado()) {
                cout << "Este livro está alugado e não pode ser removido.\n";
            } else {
                lista.erase(it);
                cout << "Livro removido com sucesso!\n";
            }
            return;
        }
    }
    cout << "Livro não encontrado.\n";
}

void Biblioteca::Devolver_Livro() {
    if (!usuarioLogado) {
        cout << "Você precisa estar logado para devolver um livro.\n";
        return;
    }

    int id;
    cout << "Digite o ID do livro que deseja devolver: ";
    cin >> id;

    auto livro = buscarLivroPorId(id);
    if (livro && livro->isAlugado()) {
        livro->setAlugado(false);
        usuarioLogado->devolverLivro(id);
        cout << "Livro devolvido com sucesso!\n";
    } else {
        cout << "Livro não encontrado ou não está alugado.\n";
    }
}

// Menu principal da biblioteca
void Biblioteca::MenuBiblioteca() {
    int opcao;
    while (true) {
        cout << "\n===== MENU BIBLIOTECA =====\n";
        cout << "1. Logout\n";
        cout << "2. Adicionar Livro\n";
        cout << "3. Listar Livros Disponíveis\n";
        cout << "4. Alugar Livro\n";
        cout << "5. Listar Meus Livros Alugados\n";
        cout << "6. Editar Livro\n";
        cout << "7. Remover Livro\n";
        cout << "8. Devolver Livro\n";
        cout << "0. Voltar ao Menu de Login\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 0) break;

        switch (opcao) {
            case 1: Logout(); break;
            case 2: Adicionar_Livro(); break;
            case 3: Listar_Livros(); break;
            case 4: Alugar_Livro(); break;
            case 5: Listar_Livros_Alugados(); break;
            case 6: Editar_Livro(); break;
            case 7: Remover_Livro(); break;
            case 8: Devolver_Livro(); break;
            default: cout << "Opção inválida!\n";
        }
    }
}