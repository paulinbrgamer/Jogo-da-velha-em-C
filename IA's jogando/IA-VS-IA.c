#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>

void verificar(int lista[9][2],int c,int l)
{
    for (int p1 =0;p1<9;p1++)
    {
        
        if (lista[p1][0] == c )
        {
            if (lista[p1][1] == l)
            {
                //printf("%d,%d",lista[p1][0],lista[p1][1]);
                lista[p1][0] = 10;
                lista[p1][1] = 10;
                //printf("\n%d,%d",lista[p1][0],lista[p1][1]);
                 //system("pause");
            }
           

        }
        
    }
}
int  aleatorio()
{
    int numero;
    srand(time(NULL)^getpid()^ rand()) ;
    numero = rand() %10;

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
        system("cls");
        printf("\n   !!REINICIANDO!!\n");
        
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
    printf("-------JOGO DA VELHA--------\n\n" );
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
    int c1=0;
    int jogada;
    int p_disponivel[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
    int backup[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
    int fim = 0;
    int ale = 0;
    char vez = 'O';
    //variaveis de jogadores
    int colunap1 = 4;
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
            
        
        //OOX
            if(tela[0][0] == 'X' && tela[0][1] == 'X'&& tela[0][2] == ' ' )
            {

                colunap1 = 0;
                linhap1 = 2;
                vez = 'X';
            }
            if(tela[0][0] == 'X' && tela[1][1] == 'X' && tela[2][2] == ' ' )
            {

                colunap1 = 2;
                linhap1 = 2;
                vez = 'X';
            }
            if(tela[0][0] == 'X' && tela[1][0] == 'X' && tela[2][0] == ' ')
            {
                colunap1 = 2;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[1][0] == 'X' && tela[1][1] == 'X' && tela[1][2] == ' ')
            {
                colunap1 = 1;
                linhap1 = 2;
                vez = 'X';
            }
            if(tela[2][0] == 'X' && tela[2][1] == 'X' && tela[2][2] == ' ')
            {
                colunap1 = 2;
                linhap1 = 2;
                vez = 'X';
            }
            if(tela[2][0] == 'X' && tela[1][1] == 'X' && tela[0][2] == ' ')
            {
                colunap1 = 0;
                linhap1 = 2;
                vez = 'X';
            }
            if(tela[0][1] == 'X' && tela[1][1] == 'X' && tela[2][1] == ' ')
            {
                colunap1 = 2;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[0][2] == 'X' && tela[1][2] == 'X' && tela[2][2] == ' ')
            {
                colunap1 = 2;
                linhap1 = 2;
                vez = 'X';
            }

            //VERIFICAR  XOO
            if(tela[0][0] == ' ' && tela[0][1] == 'X' && tela[0][2] == 'X' )
            {

                colunap1 = 0;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[0][0] == ' ' && tela[1][1] == 'X' && tela[2][2] == 'X' )
            {

                colunap1 = 0;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[0][0] == ' ' && tela[1][0] == 'X' && tela[2][0] == 'X')
            {
                colunap1 = 0;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[1][0] == ' ' && tela[1][1] == 'X' && tela[1][2] == 'X')
            {
                colunap1 = 1;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[2][0] == ' ' && tela[2][1] == 'X' && tela[2][2] == 'X')
            {
                colunap1 = 2;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[2][0] == ' ' && tela[1][1] == 'X' && tela[0][2] == 'X')
            {
                colunap1 = 2;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[0][1] == ' ' && tela[1][1] == 'X' && tela[2][1] == 'X')
            {
                colunap1 = 0;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[0][2] == ' ' && tela[1][2] == 'X' && tela[2][2] == 'X')
            {
                colunap1 = 0;
                linhap1 = 2;
                vez = 'X';
            }
            
        //VERIFICAR EM DISTANCIA 0X0
            if(tela[0][0] == 'X' && tela[0][1] == ' ' && tela[0][2] == 'X' )
            {

                colunap1 = 0;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[0][0] == 'X' && tela[1][1] == ' ' && tela[2][2] == 'X' )
            {

                colunap1 = 1;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[0][0] == 'X' && tela[1][0] == ' ' && tela[2][0] == 'X')
            {
                colunap1 = 1;
                linhap1 = 0;
                vez = 'X';
            }
            if(tela[1][0] == 'X' && tela[1][1] == ' ' && tela[1][2] == 'X')
            {
                colunap1 = 1;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[2][0] == 'X' && tela[2][1] == ' ' && tela[2][2] == 'X')
            {
                colunap1 = 2;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[2][0] == 'X' && tela[1][1] == ' ' && tela[0][2] == 'X')
            {
                colunap1 = 1;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[0][1] == 'X' && tela[1][1] == ' ' && tela[2][1] == 'X')
            {
                colunap1 = 1;
                linhap1 = 1;
                vez = 'X';
            }
            if(tela[0][2] == 'X' && tela[1][2] == ' ' && tela[2][2] == 'X')
            {
                colunap1 = 1;
                linhap1 = 2;
                vez = 'X';
            } 
            
           if(tela[0][0] == 'X' && tela[2][1] == 'X' && tela[2][0] == ' ' && vez =='O')
            {
                colunap1 = 2;
                linhap1 = 0;
                vez = 'X';
            }
           if(tela[0][0] == 'X' && tela[1][2] == 'X' && tela[0][2] == ' ' && vez =='O')
            {
                colunap1 = 0;
                linhap1 = 2;
                vez = 'X';
            }
           
           
           if (tela[1][1] == 'X')
           {
                if(tela[0][0] == ' '&& vez =='O')
                {
                    colunap1 = 0;
                    linhap1 = 0;
                    vez = 'X';
                }
                if(tela[0][2] == ' '&& vez =='O')
                {
                colunap1 = 0;
                linhap1 = 2;
                vez = 'X';
                }
                if(tela[2][2] == ' '&& vez =='O')
                {
                colunap1 = 2;
                linhap1 = 2;
                vez = 'X';
                }
                if(tela[2][0] == ' '&& vez =='O')
                {
                colunap1 = 0;
                linhap1 = 2;
                vez = 'X';
                }
           }

           


        if (vez =='O' )
        {
            printf("\njogada vai ser aleatoria:\n");
            jogada = aleatorio();
            while (p_disponivel[jogada][0]>3 )
            {

            srand(time(NULL)^getpid()^ rand());
            jogada = aleatorio();
            }

            
            colunap1 = p_disponivel[jogada][0];
            linhap1 = p_disponivel[jogada][1];
            while (tela[colunap1][linhap1] !=' ')
            {
                jogada = aleatorio();
                while (p_disponivel[jogada][0]>3 )
                {
                
                srand(time(NULL)^getpid()^ rand());
                jogada = aleatorio();
                }
                 colunap1 = p_disponivel[jogada][0];
                linhap1 = p_disponivel[jogada][1];
            }
            vez = 'X'; 
             
        }
        
        //colocar na matriz
        if (colunap1 == 0)
        {
            tela[0][linhap1] = 'O';  
        }
        if (colunap1 == 1)
        {
             tela[1][linhap1] = 'O';   
        }
        if (colunap1 == 2)
        {
             tela[2][linhap1] = 'O';  
        }
            system("cls");
            mostrar(tela);
            printf("\n    VEZ DE [ X ]");
            Sleep(1000);
            

        verificar(p_disponivel,colunap1,linhap1);
        
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
            for (int i= 0;i<9;i++)
            {
                p_disponivel[i][0]= backup[i][0];
                p_disponivel[i][1]= backup[i][1];
            }
            
        }
        //NPC IA
        if (vez == 'X')
        {
            
            
            
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
                
        if (vez =='X' )
        {
            printf("\njogada vai ser aleatoria:\n");
            jogada = aleatorio();
            while (p_disponivel[jogada][0]>3 )
            {

            srand(time(NULL)^getpid()^ rand());
            jogada = aleatorio();
            }

            
            colunap2 = p_disponivel[jogada][0];
            linhap2 = p_disponivel[jogada][1];
            while (tela[colunap2][linhap2] !=' ')
            {
                jogada = aleatorio();
                while (p_disponivel[jogada][0]>3 )
                {
                
                srand(time(NULL)^getpid()^ rand());
                jogada = aleatorio();
                }
                 colunap2 = p_disponivel[jogada][0];
                linhap2 = p_disponivel[jogada][1];
            }
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
        
        
            system("cls");
            mostrar(tela);
            printf("\n    VEZ DE [ O ]");
            Sleep(1000);
            
            
        
        //RESETAR VARIAVEIS
        vez = 'O';
        linhap2 = 4;
        colunap2 = 4;
        //desenhar a tela
       
        
        
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
                for (int i= 0;i<9;i++)
            {
                p_disponivel[i][0]= backup[i][0];
                p_disponivel[i][1]= backup[i][1];
            }
                vez = 'O';
                                
            }
        }
    
        linhap1 = 4;
        colunap1 = 4; 
        if (velha(tela) == 1)
        {
            vez='O';
            for (int i= 0;i<9;i++)
            {
                p_disponivel[i][0]= backup[i][0];
                p_disponivel[i][1]= backup[i][1];
            }
            
        }
        
    }
    return 0;
}