#ifndef LIVRO_H
#define LIVRO_H

#include "ItemBiblioteca.h"

// Classe concreta para livros
class Livro : public ItemBiblioteca {
public:
    // Construtor de livro
    Livro(int id, string titulo, string autor);
     // Exibe dados do livro
    void exibirInformacoes() const override;
};

#endif
