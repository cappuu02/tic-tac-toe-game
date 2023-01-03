#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gamelib.h"

void quit(){
    printf("Chitemmuort Frat ro cazz\n");
    abort();
}


int main(){
    int a = 0;
    system("clear");
    printf("BENVENUTO IN TRIS\n");
    printf("PREMI ENTER PER CONTINUARE...\n");
    while((getchar()) != '\n');
    printf("\n");
    
    printf("scegli cosa vuoi fare\n1] Start a Game\n2] Quit Game\n");
    scanf("%d", &a);
    switch(a){
        case 1:
            combatti();
        break;
        case 2:
            quit();
        break;
    }
    
    
    
}//fine main