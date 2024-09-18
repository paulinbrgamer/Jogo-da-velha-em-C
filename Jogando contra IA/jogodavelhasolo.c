#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h> 
int  aleatorio()
{
    int numero;
    srand(time(NULL));
    numero = rand() %3;

    return numero;
}
  velha(char tela[3][3])
{
    int contador =0;
    for(int i=0;i<3;i++)
    {   
        for (int l=0;l<3;l++)
        {
            if (tela[i][l] != ' ')
            {
                contador++;
            }
        }
    }
    if (contador == 9)
    {
        printf("\n   !!REINICIANDO!!\n");
        system("pause");
        resetar(tela);
        
        return 1;
    }
}

void resetar(char tela[3][3])
{
for(int i=0;i<3;i++)
    {   
        for (int l=0;l<3;l++)
        {
            tela[i][l] = ' ';
        }
    }
}
char mostrar(char matriz[3][3])
{
    printf("-----------VELHA-BET-----------\n\n" );
    printf("         1   2   3\n\n");
    for(int i=0;i<3;i++)
    {
        if (i==0)
        {
            printf("   A  ");
        }
        if (i==1)
        {
            printf("   B  ");
        }
        if (i==2)
        {
            printf("   C  ");
        }
        printf("  ");
        for (int l=0;l<3;l++)
        {
            printf(" %c ",matriz[i][l]);

            
            if (l+1 % 2 !=0 && l!= 2&& l!= 4&& l!= 6&& l!= 8)
            {
                printf("|");
            }
        }
        if (i<2)
        {
          printf("\n        --- --- ---");  
        }
        
        printf("\n");
        
    }
   printf("\n\n");
}
int main()
{
    //variavel de jogo
    int fim = 0;
    
    char vez = 'O';
    //variaveis de jogadores
    char colunap1 = ' ';
    int linhap1 = 4;
    int colunap2= 3;
    int linhap2 = 4;
    char tela[3][3] = 
    {
     {' ',' ',' '},
     {' ',' ',' '},
     {' ',' ',' '}
     };

    //desenhar tela
    while (fim ==0)
    {
        //jogador 1
        if (vez == 'O')
        {

        //TRATAMENTO DE BUG PARA O JOGADOR NAO JOGAR EM UM LUGAR QUE JA FOI JOGADO
        //CASO O USUARIO DIGITE UMA LETRA DIFERENTE OU UM NUMERO MAIOR QUE 3 ou no primeiro valor digite um numero ou no segundo valor digite uma letra
         while (1) {
                system("cls");
                mostrar(tela);
                printf("\n    VEZ DE [ O ] = ");

                // Lê a entrada e verifica se é válida
                if (scanf(" %c%d", &colunap1, &linhap1) != 2) {
                    // Se a entrada não for composta por uma letra e um número, limpa o buffer e avisa o usuário
                    printf("Entrada inválida! Tente novamente (Ex: A1, B2...)\n");
                    while (getchar() != '\n');  // Limpa o buffer
                    continue;
                }

                // Converter coluna para maiúscula
                colunap1 = toupper(colunap1);

                // Verifica se a linha está no intervalo certo (1 a 3)
                if (linhap1 < 1 || linhap1 > 3) {
                    printf("Linha inválida! Digite um número entre 1 e 3.\n");
                    continue;
                }

                // Verifica se a coluna está no intervalo certo (A, B ou C)
                if (colunap1 != 'A' && colunap1 != 'B' && colunap1 != 'C') {
                    printf("Coluna inválida! Digite A, B ou C.\n");
                    continue;
                }

                // Verifica se o local já está ocupado
                int colunaIndex = colunap1 - 'A';  // Converte A, B, C para 0, 1, 2
                if (tela[colunaIndex][linhap1 - 1] != ' ') {
                    printf("Posição já ocupada! Escolha outra.\n");
                    continue;
                }

                // Se todas as verificações passarem, a entrada é válida
                break;
            }
        //JOGADA DO JOGADOR DEPOIS DE FILTRAR TODOS OS POSSIVEIS ERROS
        if (colunap1 == 'A')
        {
            tela[0][linhap1-1] = 'O';  
        }
        if (colunap1 == 'B')
        {
             tela[1][linhap1-1] = 'O';   
        }
        if (colunap1 == 'C')
        {
             tela[2][linhap1-1] = 'O';  
        }
        //ATUALIZAR TELA
        system("cls");
        mostrar(tela);
        vez = 'X';
        
        //verificar as possibilidades de vitoria
        if(tela[0][0] == 'O' && tela[0][1] == 'O' && tela[0][2] == 'O'
        || tela[0][0] == 'O' && tela[1][1] == 'O' && tela[2][2] == 'O' 
        || tela[0][0] == 'O' && tela[1][0] == 'O' && tela[2][0] == 'O'
        || tela[1][0] == 'O' && tela[1][1] == 'O' && tela[1][2] == 'O'
        || tela[2][0] == 'O' && tela[2][1] == 'O' && tela[2][2] == 'O'
        || tela[2][0] == 'O' && tela[1][1] == 'O' && tela[0][2] == 'O'
        || tela[0][1] == 'O' && tela[1][1] == 'O' && tela[2][1] == 'O'
        || tela[0][2] == 'O' && tela[1][2] == 'O' && tela[2][2] == 'O')
            {
                printf("    !!VOCE GANHOU!!\n");
                system("pause");
                resetar(tela);
                vez = 'O';
                
            }
        }
        
        if (velha(tela) == 1)
        {
            vez='O';
        }
        //NPC IA
        if (vez == 'X')
        {
            
            
            system("cls");
            mostrar(tela);
            printf("\n    VEZ DE [ X ]");
            Sleep(800);
        //nao deixar o jogador vencer na roadada atual
        //VERIFICAR EM SEQUENCIA OOX
    
            if(tela[0][0] == 'O' && tela[0][1] == 'O' && tela[0][2] == ' ' )
            {

                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][0] == 'O' && tela[1][1] == 'O' && tela[2][2] == ' ' )
            {

                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][0] == 'O' && tela[1][0] == 'O' && tela[2][0] == ' ')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[1][0] == 'O' && tela[1][1] == 'O' && tela[1][2] == ' ')
            {
                colunap2 = 1;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[2][0] == 'O' && tela[2][1] == 'O' && tela[2][2] == ' ')
            {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[2][0] == 'O' && tela[1][1] == 'O' && tela[0][2] == ' ')
            {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][1] == 'O' && tela[1][1] == 'O' && tela[2][1] == ' ')
            {
                colunap2 = 2;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][2] == 'O' && tela[1][2] == 'O' && tela[2][2] == ' ')
            {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }

            //VERIFICAR  XOO
            if(tela[0][0] == ' ' && tela[0][1] == 'O' && tela[0][2] == 'O' )
            {

                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[0][0] == ' ' && tela[1][1] == 'O' && tela[2][2] == 'O' )
            {

                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[0][0] == ' ' && tela[1][0] == 'O' && tela[2][0] == 'O')
            {
                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[1][0] == ' ' && tela[1][1] == 'O' && tela[1][2] == 'O')
            {
                colunap2 = 1;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][0] == ' ' && tela[2][1] == 'O' && tela[2][2] == 'O')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][0] == ' ' && tela[1][1] == 'O' && tela[0][2] == 'O')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[0][1] == ' ' && tela[1][1] == 'O' && tela[2][1] == 'O')
            {
                colunap2 = 0;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][2] == ' ' && tela[1][2] == 'O' && tela[2][2] == 'O')
            {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
            
        //VERIFICAR EM DISTANCIA 0X0
            if(tela[0][0] == 'O' && tela[0][1] == ' ' && tela[0][2] == 'O' )
            {

                colunap2 = 0;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][0] == 'O' && tela[1][1] == ' ' && tela[2][2] == 'O' )
            {

                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][0] == 'O' && tela[1][0] == ' ' && tela[2][0] == 'O')
            {
                colunap2 = 1;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[1][0] == 'O' && tela[1][1] == ' ' && tela[1][2] == 'O')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[2][0] == 'O' && tela[2][1] == ' ' && tela[2][2] == 'O')
            {
                colunap2 = 2;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[2][0] == 'O' && tela[1][1] == ' ' && tela[0][2] == 'O')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][1] == 'O' && tela[1][1] == ' ' && tela[2][1] == 'O')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][2] == 'O' && tela[1][2] == ' ' && tela[2][2] == 'O')
            {
                colunap2 = 1;
                linhap2 = 2;
                vez = 'O';
            } 
            
            if(tela[0][0] == 'O' && tela[2][1] == 'O' && tela[2][0] == ' ' && vez =='X')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][0] == 'O' && tela[0][1] == 'O' && tela[0][0] == ' '&& vez =='X')
            {
                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][2] == 'O' && tela[0][1] == 'O' && tela[0][2] == ' '&& vez =='X')
            {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][2] == 'O' && tela[2][1] == 'O' && tela[2][2] == ' '&& vez =='X')
            {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }
            //DE B
             if(tela[1][0] == 'O' && tela[2][2] == 'O' && tela[2][0] == ' '&& vez =='X')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }

            //jogada doida
             if(tela[0][1] == 'O' && tela[1][0] == 'O' && tela[0][0] == ' '&& vez =='X')
            {
                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
             if(tela[0][1] == 'O' && tela[1][2] == 'O' && tela[0][2] == ' '&& vez =='X')
            {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
             if(tela[2][1] == 'O' && tela[1][0] == 'O' && tela[2][0] == ' '&& vez =='X')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][1] == 'O' && tela[1][2] == 'O' && tela[2][2] == ' '&& vez =='X')
            {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }
        //verificar se é possivel vencer na jogada atual
        //VERIFICAR XX0
            if(tela[0][0] == 'X' && tela[0][1] == 'X' && tela[0][2] == ' ' )
            {

                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][0] == 'X' && tela[1][1] == 'X' && tela[2][2] == ' ' )
            {

                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][0] == 'X' && tela[1][0] == 'X' && tela[2][0] == ' ')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[1][0] == 'X' && tela[1][1] == 'X' && tela[1][2] == ' ')
            {
                colunap2 = 1;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[2][0] == 'X' && tela[2][1] == 'X' && tela[2][2] == ' ')
            {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[2][0] == 'X' && tela[1][1] == 'X' && tela[0][2] == ' ')
            {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
            if(tela[0][1] == 'X' && tela[1][1] == 'X' && tela[2][1] == ' ')
            {
                colunap2 = 2;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][2] == 'X' && tela[1][2] == 'X' && tela[2][2] == ' ')
            {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
            }

        //VERIFICAR OXX
            if(tela[0][0] == ' ' && tela[0][1] == 'X' && tela[0][2] == 'X' )
            {

                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[0][0] == ' ' && tela[1][1] == 'X' && tela[2][2] == 'X' )
            {

                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[0][0] == ' ' && tela[1][0] == 'X' && tela[2][0] == 'X')
            {
                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[1][0] == ' ' && tela[1][1] == 'X' && tela[1][2] == 'X')
            {
                colunap2 = 1;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][0] == ' ' && tela[2][1] == 'X' && tela[2][2] == 'X')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[2][0] == ' ' && tela[1][1] == 'X' && tela[0][2] == 'X')
            {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[0][1] == ' ' && tela[1][1] == 'X' && tela[2][1] == 'X')
            {
                colunap2 = 0;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][2] == ' ' && tela[1][2] == 'X' && tela[2][2] == 'X')
            {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
            }
        //VERIFICAR X0X
            if(tela[0][0] == 'X' && tela[0][1] == ' ' && tela[0][2] == 'X' )
            {

                colunap2 = 0;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][0] == 'X' && tela[1][1] == ' ' && tela[2][2] == 'X' )
            {

                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][0] == 'X' && tela[1][0] == ' ' && tela[2][0] == 'X')
            {
                colunap2 = 1;
                linhap2 = 0;
                vez = 'O';
            }
            if(tela[1][0] == 'X' && tela[1][1] == ' ' && tela[1][2] == 'X')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[2][0] == 'X' && tela[2][1] == ' ' && tela[2][2] == 'X')
            {
                colunap2 = 2;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[2][0] == 'X' && tela[1][1] == ' ' && tela[0][2] == 'X')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][1] == 'X' && tela[1][1] == ' ' && tela[2][1] == 'X')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
            if(tela[0][2] == 'X' && tela[1][2] == ' ' && tela[2][2] == 'X')
            {
                colunap2 = 1;
                linhap2 = 2;
                vez = 'O';
            } 

        //CRIAR JOGADA
        //jogada no centro
        if (tela[1][1] == ' ')
            {
                colunap2 = 1;
                linhap2 = 1;
                vez = 'O';
            }
        if (tela[1][1] == 'X')
        {
            // JOGADAS DE MEIO
            if (tela[0][1] == ' '&& vez == 'X')
                {
                    colunap2 = 0;
                    linhap2 = 1;
                    vez = 'O'; 
                }
                 if (tela[2][1] == ' '&& vez == 'X')
                {
                    colunap2 = 2;
                    linhap2 = 1;
                    vez = 'O'; 
                }
            if (tela[1][0] == ' '&& vez == 'X')
                {
                    colunap2 = 1;
                    linhap2 = 0;
                    vez = 'O'; 
                }

           
            
            if (tela[1][2] == ' '&& vez == 'X')
                {
                    colunap2 = 1;
                    linhap2 = 2;
                    vez = 'O'; 
                }
        

        }
        //Jogada de quina
        if (tela[0][0] == ' ' && vez=='X')
        {
                colunap2 = 0;
                linhap2 = 0;
                vez = 'O';
        }
        if (tela[2][0] == ' ' && vez=='X')
        {
                colunap2 = 2;
                linhap2 = 0;
                vez = 'O';
        }
        if (tela[0][2] == ' ' && vez=='X')
        {
                colunap2 = 0;
                linhap2 = 2;
                vez = 'O';
        }
        if (tela[2][2] == ' ' && vez=='X')
        {
                colunap2 = 2;
                linhap2 = 2;
                vez = 'O';
        }
        
        //jogada de meio sem o X no centro
        if (tela[1][0] == ' '&& vez == 'X')
                {
                    colunap2 = 1;
                    linhap2 = 0;
                    vez = 'O'; 
                }

            if (tela[2][1] == ' '&& vez == 'X')
                {
                    colunap2 = 2;
                    linhap2 = 1;
                    vez = 'O'; 
                }
            if (tela[0][1] == ' '&& vez == 'X')
                {
                    colunap2 = 0;
                    linhap2 = 1;
                    vez = 'O'; 
                }
            if (tela[1][2] == ' '&& vez == 'X')
                {
                    colunap2 = 1;
                    linhap2 = 2;
                    vez = 'O'; 
                }
        

        //INSERIR NA MATRIZ
        if (colunap2 == 0)
        {
            tela[0][linhap2] = 'X';  
        }
        if (colunap2 == 1)
        {
             tela[1][linhap2] = 'X';   
        }
        if (colunap2 == 2)
        {
             tela[2][linhap2] = 'X';  
        }
        //RESETAR VARIAVEIS
        vez = 'O';
        linhap2 = 4;
        colunap2 = 4;
        //desenhar a tela
        system("cls");
        mostrar(tela);
        
        //verificar as possibilidades de vitoria
        if(tela[0][0] == 'X' && tela[0][1] == 'X' && tela[0][2] == 'X'
        || tela[0][0] == 'X' && tela[1][1] == 'X' && tela[2][2] == 'X' 
        || tela[0][0] == 'X' && tela[1][0] == 'X' && tela[2][0] == 'X'
        || tela[1][0] == 'X' && tela[1][1] == 'X' && tela[1][2] == 'X'
        || tela[2][0] == 'X' && tela[2][1] == 'X' && tela[2][2] == 'X'
        || tela[2][0] == 'X' && tela[1][1] == 'X' && tela[0][2] == 'X'
        || tela[0][1] == 'X' && tela[1][1] == 'X' && tela[2][1] == 'X'
        || tela[0][2] == 'X' && tela[1][2] == 'X' && tela[2][2] == 'X')
            {
                printf("   !!VOCE PERDEU!!\n");
                system("pause");
                resetar(tela);
                vez = 'O';
                                
            }
        }
    
       linhap1 = 4;
        colunap1 = ' '; 
        if (velha(tela) == 1)
        {
            vez='O';
        }
        
    }
    return 0;
}