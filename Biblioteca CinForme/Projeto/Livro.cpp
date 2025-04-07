#include "Livro.h"
#include <iostream>
using namespace std;

// Construtor do livro
Livro::Livro(int id, string titulo, string autor)
    : ItemBiblioteca(id, titulo, autor) {}

// Exibe informações do livro
void Livro::exibirInformacoes() const {
    cout << "ID: " << id
         << " | Título: " << titulo
         << " | Autor: " << autor
         << " | " << (alugado ? "Alugado" : "Disponível") << endl;
}
