#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gamelib.h"


//definizione variabili globali
int tavolo[3][3];//definire matrice
int turno = 1;
int a, b = 0;
bool flag1 = false;


void titolo(){
    printf(" .----------------.  .----------------.  .----------------.  .----------------. \n");
    printf("| .--------------. || .--------------. || .--------------. || .--------------. |\n");
    printf("| |  _________   | || |  _______     | || |     _____    | || |    _______   | |\n");
    printf("| | |  _   _  |  | || | |_   __  |   | || |    |_   _|   | || |   /  ___  |  | |\n");
    printf("| | |   | |   |  | || |   | |__) |   | || |      | |     | || |  |  (__ |_|  | |\n");
    printf("| |     | |      | || |   |  __ /    | || |      | |     | || |   '.___`-.   | |\n");
    printf("| |    _| |_     | || |  _| |  | |_  | || |     _| |_    | || |  |`|____) |  | |\n");
    printf("| |   |_____|    | || | |____| |___| | || |    |_____|   | || |  |_______.'  | |\n");
    printf("| |              | || |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------'  '----------------' \n");
}


//funzione che controlla chi vince
bool controllo(int x){
    int count1, count2 = 0;
    if(tavolo[0][0] == x && tavolo[1][1] == x && tavolo[2][2] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    if(tavolo[0][0] == x && tavolo[0][1] == x && tavolo[0][2] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    if(tavolo[1][0] == x && tavolo[1][1] == x && tavolo[1][2] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    if(tavolo[2][0] == x && tavolo[2][1] == x && tavolo[2][2] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    if(tavolo[0][0] == x && tavolo[1][0] == x && tavolo[2][0] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    if(tavolo[0][1] == x && tavolo[1][1] == x && tavolo[2][1] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    if(tavolo[0][2] == x && tavolo[1][2] == x && tavolo[2][2] == x){
        printf("il giocatore %d ha vinto il game\n", x);
        return true;
    }
    else{
        return false;
    }
}




//funzione stampa campo
void stampa_campo(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j< 3; j++){
            printf("%d", tavolo[i][j]);
        }
        printf("\n");
    }
}


void combatti(){
system("clear");
titolo();
printf("\n");
char player1[20];
char player2[20];

printf("digita nome player 1:\n");
scanf("%s", &player1);
printf("\n");
printf("nome giocatore 1: %s\n", player1);
printf("-------------\n");
printf("digita nome player 2:\n");
scanf("%s", &player2);
printf("\n");
printf("nome giocatore 2: %s\n", player2);
printf("\n");
printf("CLICCA [INVIO] PER INIZIARE IL GAME\n");
while((getchar()) != '\n');

system("clear");
titolo();
printf("\n");
printf("\033[1;33m   SALVATAGGIO IN CORSO\n"); 
printf("\033[1;37m     ATTENDERE PREGO!\n");
printf("\033[1;37m▇▇▇▇▇▇______________________\n");
printf("            25 \n");
sleep(1);
system("clear");
titolo();
printf("\n");
printf("\033[1;33m   SALVATAGGIO IN CORSO\n");
printf("\033[1;37m     ATTENDERE PREGO!\n");
printf("\033[1;37m▇▇▇▇▇▇▇▇▇▇▇▇▇▇______________\n");
printf("            50 \n");
sleep(1);
system("clear");
titolo();
printf("\n");
printf("\033[1;33m   SALVATAGGIO COMPLETATO\n");
printf("\033[1;33mPREMI INVIO PER CONTINUARE!\n");
printf("\033[1;37m▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n");
printf("            100 \n");
while((getchar()) != '\n');




//creazione campo gioco
for(int i = 0; i < 3; i++){
    for(int j = 0; j< 3; j++){
        tavolo[i][j] = 0;
    }
}

printf("tavolo da gioco\n");
printf("----\n");
stampa_campo();
printf("----\n");
printf("\n");
system("clear");

titolo();
printf("\n");
while(flag1 == false){
    if(turno == 1){
        printf("TURNO GIOCATORE 1\n");
        printf("\n");
        stampa_campo();
        printf("\n");
        do{
        do{
        printf("scegli il nm di riga:\n");
        scanf("%d", &a);
        if(a < 0 || a >= 3){
            printf("\nERROR, digitare numero tra 0 e 2\n");
        }
        }while(a < 0 || a >= 3);
        do{
        printf("scegli il nm di colonna:\n");
        scanf("%d", &b);
        if(b < 0 || b >= 3){
            printf("\nERROR, digitare numero tra 0 e 2\n");
        }
        }while(b < 0 || b >= 3);
        
        if(tavolo[a][b] != 0){
            printf("Slot già selezionato dall'avversario!\n");
        }
    }while(tavolo[a][b] != 0);
        if(tavolo[a][b] == 0){
            tavolo[a][b] = 1;
            printf("\ngiocata effettuata, tavolo:\n");
            stampa_campo();
            printf("----------\n");
            flag1 = controllo(1);
            ++turno;
        }
        
    }
    else if(turno == 2){
        printf("TURNO GIOCATORE 2\n");
        printf("\n");
        stampa_campo();
        printf("\n");
        do{
        do{
        printf("scegli il nm di riga\n");
        scanf("%d", &a);
        if(a < 0 || a >= 3){
            printf("\nERROR, digitare numero tra 0 e 2\n");
        }
        }while(a < 0 || a >= 3);
        do{
        printf("scegli il nm di colonna:\n");
        scanf("%d", &b);
        if(b < 0 || b >= 3){
            printf("\nERROR, digitare numero tra 0 e 2\n");
        }
        }while(b < 0 || b >= 3);
        
        if(tavolo[a][b] != 0){
            printf("Slot già selezionato dall'avversario!\n");
        }
    }while(tavolo[a][b] != 0);
        if(tavolo[a][b] == 0){
            tavolo[a][b] = 2;
        printf("\ngiocata effettuata, tavolo:\n");
        stampa_campo();
        printf("----------\n");
        flag1 = controllo(2);
        --turno;
        }
        
    }
}
 
}//fine main




