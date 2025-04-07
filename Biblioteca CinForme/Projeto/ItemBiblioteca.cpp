#include "ItemBiblioteca.h"

// Construtor do item da biblioteca
ItemBiblioteca::ItemBiblioteca(int id, string titulo, string autor)
    : id(id), titulo(titulo), autor(autor), alugado(false) {}
// Getters
int ItemBiblioteca::getId() const { return id; }
string ItemBiblioteca::getTitulo() const { return titulo; }
string ItemBiblioteca::getAutor() const { return autor; }
bool ItemBiblioteca::isAlugado() const { return alugado; }
// Setters
void ItemBiblioteca::setTitulo(string novoTitulo) { titulo = novoTitulo; }
void ItemBiblioteca::setAutor(string novoAutor) { autor = novoAutor; }
void ItemBiblioteca::setAlugado(bool status) { alugado = status; }
