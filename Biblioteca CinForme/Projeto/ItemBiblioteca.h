#ifndef ITEMBIBLIOTECA_H
#define ITEMBIBLIOTECA_H

#include <string>
using namespace std;

// Classe base para itens da biblioteca
class ItemBiblioteca {
protected:
    int id;
    string titulo;
    string autor;
    bool alugado;

public:
    ItemBiblioteca(int id, string titulo, string autor); // Construtor base
    virtual void exibirInformacoes() const = 0; // Interface para exibir dados
    virtual ~ItemBiblioteca() {}
    // Getters
    int getId() const;
    string getTitulo() const;
    string getAutor() const;
    bool isAlugado() const;
    // Setters
    void setTitulo(string novoTitulo);
    void setAutor(string novoAutor);
    void setAlugado(bool status);
};

#endif
