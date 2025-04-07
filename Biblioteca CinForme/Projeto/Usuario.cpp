#include "Usuario.h"
#include <algorithm>

// Construtor do usuário
Usuario::Usuario(string nomeUsuario, string senha)
    : nomeUsuario(nomeUsuario), senha(senha) {}

string Usuario::getNomeUsuario() const { return nomeUsuario; }

// Verifica se a senha está correta
bool Usuario::autenticar(string senhaDigitada) const {
    return senhaDigitada == senha;
}

// Adiciona livro alugado
void Usuario::alugarLivro(int idLivro) {
    livrosAlugados.push_back(idLivro);
}

// Remove livro da lista de alugados
void Usuario::devolverLivro(int idLivro) {
    livrosAlugados.erase(remove(livrosAlugados.begin(), livrosAlugados.end(), idLivro), livrosAlugados.end());
}

const vector<int>& Usuario::getLivrosAlugados() const {
    return livrosAlugados;
}