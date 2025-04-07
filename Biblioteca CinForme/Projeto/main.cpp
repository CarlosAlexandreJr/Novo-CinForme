#include "Biblioteca.h"
#include <iostream>
using namespace std;

// Função principal (inicia menus de login e biblioteca)
int main() {
    // Criando nova biblioteca
    Biblioteca biblioteca;
    int opcao;
    bool executando = true;
    // Primeiro Menu
    while (executando) {
        cout << "\n===== MENU LOGIN =====\n";
        cout << "1. Cadastrar Usuário\n";
        cout << "2. Login\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        // Lendo a opcao
        cin >> opcao;
        // Verificando a opcao escolhida
        switch (opcao) {
            case 1:
                biblioteca.Cadastrar_Usuario();
                break;
            case 2:
                biblioteca.Login();
                break;
            case 0:
                executando = false;
                break;
            default:
                cout << "Opção inválida!\n";
        }
    }

    cout << "Saindo...\n";
    return 0;
}
