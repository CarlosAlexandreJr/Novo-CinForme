#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Livro.h"
#include "Usuario.h"
#include <vector>
#include <memory>

const int TAMANHO_TABELA = 100; // Tamanho da tabela hash

// Gerencia livros e usuarios
class Biblioteca {
private:
    vector<shared_ptr<ItemBiblioteca>> tabelaLivros[TAMANHO_TABELA]; // Hash table
    vector<Usuario> usuarios;
    Usuario* usuarioLogado = nullptr; // Ponteiro
    int proximoId = 1;

    int hash(int id); // Calcula o index na hash
    shared_ptr<ItemBiblioteca> buscarLivroPorId(int id); // Busca livro por ID

public:
    void Cadastrar_Usuario(); // Cadastro
    void Login(); // Login
    void Logout(); // Logout

    void Adicionar_Livro(); // Cadastrar novo livro
    void Listar_Livros(); // Listar livros disponiveis
    void Alugar_Livro(); // Alugar livro
    void Devolver_Livro(); // Devolver livro alugado
    void Listar_Livros_Alugados(); // Ver livros alugados pelo usuario
    void Editar_Livro(); // Editar dados de livro
    void Remover_Livro(); // Excluir livro
    void MenuBiblioteca(); // Menu principal
};

#endif
