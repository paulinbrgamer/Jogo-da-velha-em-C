#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#define lin 20
#define col 30
//tela
char tecla;
char tela[lin][col];

//cobra
int cobra[200][2] = {{5,11},{5,10},{5,9}};
int direx=1;
int direy=0;
int bol = 1;
int boly = 0;
int rabo = 3;
//jogo
int score=0;
char fruta = 'o';
int posi_fruta[2] = {10,4};

int lower = 1; // Limite inferior do intervalo
int upper = 18;

//game state
int paused = 0;
char escolha;
void main(void) {
    
    
//game loop
    while (1)
    {
        if (paused == 0)
        {
        //----------------------UP-------------------------
        printf("-----------------------SNACK DO PAULIN---------------------\n\n");
        printf("SCORE: %d \n\n",score);
        //LIMPAR a tela a cada frame
        for (int i = 0;i<lin;i++)
        {
            for (int j=0;j<col;j++)
            {
                if (i==0 || i==19)
                {
                tela[i][j] = '=';    
                }
                else
                {
                if (j==0 || j==29)
                {
                tela[i][j] = '=';    
                }
                else{
                tela[i][j] = ' ';
                }
                } 
            }
        }


        //receber input
        if (kbhit())
        {
            tecla = _getch();
            //mudar a direção para esquerda
            if (tecla=='d' && bol==0   || tecla =='D' && bol==0)
            {
                direx = 1;
                direy = 0;
                bol = 1;
                boly=0;
            }
            //mudar a direção para DIREITA
            if (tecla=='a' && bol== 0  || tecla =='A'&& bol== 0)
            {
                direx = -1;
                direy= 0;
                bol = 1;
                boly= 0;
            }
            //mudar a direção para baixo
            if (tecla =='s' && boly ==0|| tecla=='S'&& boly ==0)
            {
                direy = 1;
                direx = 0;
                bol = 0;
                boly=1;
            }
            //mudar a direção para Cima
            if (tecla =='w' && boly ==0|| tecla=='W'&& boly ==0)
            {
                direy = -1;
                direx = 0;
                bol = 0;
                boly=1;
            }
        }

        //Fazer a cobra seguir a direção x positiva
        if (direx >0 )
        {
            for (int i =rabo;i>0;i--)
            {
                cobra[i][1] = cobra[i-1][1];
                cobra[i][0] = cobra[i-1][0];
            }
            cobra[0][1] = cobra[0][1]+1;    
        }
        //Fazer a cobra seguir a direção x negativa
        if (direx <0 )
        {
            for (int i =rabo;i>0;i--)
            {
                cobra[i][1] = cobra[i-1][1];
                cobra[i][0] = cobra[i-1][0];
            }
            cobra[0][1] = cobra[0][1]-1;   
        }
        //Fazer a cobra seguir a direção y positiva
        if (direy>0)
        {
            for (int i =rabo;i>0;i--)
            {
                cobra[i][0] = cobra[i-1][0];
                cobra[i][1] = cobra[i-1][1];
            }
            cobra[0][0] = cobra[0][0]+1;
            
        }
        //Fazer a cobra seguir a direção y negativa
        if (direy<0)
        {
            for (int i =rabo;i>0;i--)
            {
                cobra[i][1] = cobra[i-1][1];
                cobra[i][0] = cobra[i-1][0];
            }
            cobra[0][0] = cobra[0][0]-1;
        }
        

        //verificar colisão com frutae adicionar tamanho ao rabo e ao score
        if (posi_fruta[0] == cobra[0][0] && posi_fruta[1] == cobra[0][1])
        {
            score++;
            cobra[rabo][0] = cobra[rabo-1][0];
            cobra[rabo][1] = cobra[rabo-1][1];
            rabo++;

            //mudar a posiçao da fruta
            srand(time(NULL));
            posi_fruta[0] = (rand() % (upper-lower +1))+lower;
            srand(time(NULL));
            posi_fruta[1] = (rand() % (28-lower +1))+lower;
        }

        //Verificar colisão da cobra com a tela 
        
        //colisao com o rabo da cobra

        for (int i =1;i<rabo;i++)
        {
            if (cobra[0][0] == cobra[i][0] && cobra[0][1] == cobra[i][1])
            {
                paused=1;
            }
        }
        //incerir a cobra na tela
        for (int i =0;i<rabo;i++)
        {
            tela[cobra[i][0]][cobra[i][1]] = 'O';
        }
        
        
        //incerir fruta
        tela[posi_fruta[0]][posi_fruta[1]] = fruta;
        
        //----------------------DRAWN-------------------------
        for (int i = 0;i<lin;i++)
        {
            for (int j=0;j<col;j++)
            {
                printf("%c ",tela[i][j]);
            }
            printf("\n");

        }
        usleep(1000000/40);
        system("cls");
        }
        else{
            rabo = 3;
            score = 0;
            cobra[0][0] = 5;
            cobra[0][1] = 11;
            cobra[1][0] = 5;
            cobra[1][1] = 10;
            cobra[2][0] = 5;
            cobra[2][1] = 9;
            direy = 0;
            direx = 1;
            bol = 1;
            boly = 0;
         printf("Deseja jogar novamente?[S/N]: ");
        scanf("%c",&escolha);
        getchar();

        if (escolha == 'S')
        {
            paused = 0;
        }
        else{
            break;
        }
        }
        
    }
    



}
