#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//definizione variabili globali
int tavolo[3][3];//definire matrice
int turno = 1;
int a, b = 0;
bool flag1 = false;
int timer = 0;

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


int main(){
char player1;
char player2;

printf("digita nome player 1:\n");
scanf("%s", &player1);
printf("digita nome player 2:\n");
scanf("%s", &player2);

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


while(flag1 == false && timer < 9){
    if(turno == 1){
        printf("TURNO GIOCATORE 1\n");
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
            timer++;
        }
        
    }
    else if(turno == 2){
        printf("TURNO GIOCATORE 2\n");
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
        timer++;
        }
        
    }
}
if(timer == 9){
    printf("gioco terminato in pareggio!\n");
}
}//fine main



