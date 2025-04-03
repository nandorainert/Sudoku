/*Equipe: Dinaê Pfiffer, Eduarda Maniezo Humenhuk, Ferdinando Rainert, Gabriel Marques, Juliana Varela*/
#include <iostream>
#include <time.h>
#include <locale>
using namespace std;

#define TAM 9

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    /*num: número sorteado para qual matriz vai ser, MatT: transposta, matIL: invertida por linha, matIC: invertida por coluna,
    matJ: jogo, matG: gabarito, matP: principal, opcao: escolha da pessoa, i e j: linha e coluna sorteados para preencher 41 posições,
    cont: contar até 41 para preencher matrizes, jogadas: quantas jogadas a pessoa fez, tentativa: recebe a tentativa da pessoa,
    it e jt: recebe a linha e coluna que a pessoa quer tentar, verificador: usado para verificar se toda a matriz foi preenchida, vitoria: caso verdadeiro finaliza o jogo*/
    int matP[TAM][TAM] = {4, 9, 5, 2, 8, 7, 3, 6, 1, 7, 2, 8, 6, 1, 3, 4, 9, 5, 3, 6, 1, 9, 5, 4, 7, 2, 8, 6, 5, 3, 8, 4, 9, 2, 1, 7, 9, 8, 4, 1, 7, 2, 6, 5, 3, 2, 1, 7, 5, 3, 6, 9, 8, 4, 1, 3, 2, 4, 6, 5, 8, 7, 9, 5, 4, 6, 7, 9, 8, 1, 3, 2, 8, 7, 9, 3, 2, 1, 5, 4, 6};
    int matG[TAM][TAM]{}, matJ[TAM][TAM]{};
    int opcao = 0, num = 0, cont = 0, jogadas = 0, tentativa, it, jt, verificador = 0;
    bool vitoria = false;

    do {
        cout << "Escolha uma opção: " << endl;
        cout << "1- Jogar. " << endl;
        cout << "2- Sobre. " << endl;
        cout << "3- Fim. " << endl;
        cin >> opcao;

        switch (opcao) {
        case 1: {
            // Determinar o tipo de matriz
            num = rand() % 4 + 1;

            if (num == 1) { // Matriz principal
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        matG[i][j] = matP[i][j];
                    }
                }
            } else if (num == 2) { // Matriz transposta
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        matG[i][j] = matP[j][i];
                    }
                }
            } else if (num == 3) { // Matriz invertida por linha
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        matG[i][j] = matP[TAM - 1 - i][j];
                    }
                }
            } else if (num == 4) { // Matriz invertida por coluna
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        matG[i][j] = matP[i][TAM - 1 - j];
                    }
                }
            }

            // Preencher 41 posições aleatórias
            cont = 0;
            while (cont < 41) {
                int i = rand() % TAM;
                int j = rand() % TAM;
                if (matJ[i][j] == 0) {
                    matJ[i][j] = matG[i][j];
                    cont++;
                }
            }

            while (!vitoria) {//Enquanto vitoria for falso fica repetindo
                // Exibe a matriz atual
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        cout << matJ[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << "Qual posição de linha deseja jogar? (1-9): ";
                cin >> it;
                it--;

                cout << "Qual posição de coluna deseja jogar? (1-9): ";
                cin >> jt;
                jt--;

                cout << "Qual número deseja jogar? (1-9): ";
                cin >> tentativa;

                if (matJ[it][jt] == 0) {
                    bool numeroInvalido = false;

                    // Verifica coluna
                    for (int i = 0; i < TAM; i++) {
                        if (matJ[i][jt] == tentativa) {
                            cout << "Número já existe nessa coluna.\n";
                            numeroInvalido = true;
                            break;
                        }
                    }

                    // Verifica linha
                    for (int j = 0; j < TAM; j++) {
                        if (matJ[it][j] == tentativa) {
                            cout << "Número já existe nessa linha.\n";
                            numeroInvalido = true;
                            break;
                        }
                    }

                    if (!numeroInvalido) {
                        matJ[it][jt] = tentativa;
                        jogadas++;
                    }
                } else {
                    cout << "Essa posição já está preenchida.\n";
                }

                // Verifica vitória
                verificador = 0;
                for (int i = 0; i < TAM; i++) {
                    for (int j = 0; j < TAM; j++) {
                        if (matJ[i][j] != 0) {
                            verificador++;
                        }
                    }
                }

                if (verificador == 81) {
                    cout << "\nParabéns! Você completou o Sudoku em " << jogadas << " jogadas!\n";
                    vitoria = true;
                }
            }
            break;
        }

        case 2: // Sobre
            cout << "Equipe: Ferdinando Rainert, Eduarda Maniezo Humenhuk, Dinaê Pfiffer, Juliana Varela, Gabriel Marques." << endl;
            cout << "Data: Novembro de 2024." << endl;
            cout << "Professor: Rafael Ballottin Martins." << endl;
            cout << "Matéria: Algoritmos e programação." << endl;
            break;

        case 3: // Fim
            cout << "Finalizando..." << endl;
            break;

        default:
            cout << "Opção inválida! Tente novamente.\n";
        }

        // Reinicializa variáveis para um novo jogo
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                matJ[i][j] = 0;
            }
        }
        cont = 0;
        jogadas = 0;
        vitoria = false;

    } while (opcao != 3);

    return 0;
}
