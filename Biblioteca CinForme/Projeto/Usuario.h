#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
using namespace std;

// Representa um usuário do sistema
class Usuario {
private:
    // Infomacoes importantes
    string nomeUsuario;
    string senha;
    vector<int> livrosAlugados; // IDs dos livros alugados

public:
    Usuario(string nomeUsuario, string senha);

    string getNomeUsuario() const;
    bool autenticar(string senhaDigitada) const;

    void alugarLivro(int idLivro); // Adiciona livro ao usuário
    void devolverLivro(int idLivro); // Remove livro alugado
    const vector<int>& getLivrosAlugados() const; // Retorna livros do usuário
};

#endif