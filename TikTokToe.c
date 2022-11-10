#include <stdio.h>
#include <windows.h>
//Tom je buh


void bait(){
    printf("Svoji vyhru si vyzvednete zde: https://www.youtube.com/watch?v=dQw4w9WgXcQ");
}

void print_table (char *table, int size){
    printf (
            "\t======================\n"
                   "\t|      |      |      |\n"
                   "\t|  %c   |  %c   |  %c   |\n"
                   "\t|      |      |      |\n"
                   "\t======================\n"
                   "\t|      |      |      |\n"
                   "\t|  %c   |  %c   |  %c   |\n"
                   "\t|      |      |      |\n"
                   "\t======================\n"
                   "\t|      |      |      |\n"
                   "\t|  %c   |  %c   |  %c   |\n"
                   "\t|      |      |      |\n"
                   "\t======================\n",
                   table[0], table[1], table[2],
                   table[3], table[4], table[5],
                   table[6], table[7], table[8]);
}

int check_answers (int *arr, int size, int num){
    for (int i = 0; i < size; i++){
        if (arr[i] == num){printf ("\nCo to zkousis hajzle jeden, to uz je obsazene\n"
                                          "Za trest ztracis kolo\n"); return 1;}
    }
    return 0;
}

void player_turn_first (char *table, int *arr, int round){
    printf ("\n Turn of player 1: \n");
    int place;
    scanf("%i", &place);
    if (check_answers(arr, 9, place - 1) != 1){
        table[place - 1] = 'X';
        arr[round] = place - 1;
    }
    else { Sleep(1000);}
}

void player_turn_second (char *table, int *arr, int round){
    printf ("\n Turn of player 2: \n");
    int place;
    scanf("%i", &place);
    if (check_answers(arr, 9, place - 1) != 1){
        table[place - 1] = 'O';
        arr[round] = place - 1;
    }
    else { Sleep(2000);}
}
int check_horizontaly (char *table){
    for (int i = 0; i < 3; i++){
        if (table[i] == table[i+1] && table[i+1] == table[i+2]){
            if (table[i] == 'X'){return 1;}
            else {return 2;}
        }
    }
    return -1;
}
int check_vertical (char *table){
    for (int i = 0; i < 3; i++){
        if (table[i] == table[i+3] && table[i+3] == table[i+6]){
            if (table[i] == 'X'){return 1;}
            else {return 2;}
        }
    }
    return -1;
}
int check_status (char *table){
    if (check_horizontaly(table) == 1 || check_vertical(table) == 1)
    {
        printf ("\nCONGRATULATIONS PLAYER 1 WON\n");
        bait();
        return 1;}
    if (check_horizontaly(table) == 2 || check_vertical(table) == 2)
    {
        printf ("\nCONGRATULATIONS PLAYER 2 WON\n");
        bait();
        return 1;        
    }

    return 0;
}
void game (void){
    char table[9] = "123456789";
    int answers[9];
    int table_size = 9;
    int status = 0;

    print_table(table, table_size);
    printf ("MATE JEN 9 TAHU, PROTOZE NA NEMAME TO CELY DEN\n");

    for (int i = 0; i < 9; i++){
        if ((i+1)%2 != 0){ player_turn_first(table, answers, i+1);}
        else {player_turn_second(table, answers, i+1);}
        if(check_status(table) != 0){printf("\nEND OF THE GAME THANKS FOR PLAYING\n"); status = 1; break;}
        print_table(table, table_size);
    }
    if(status == 0){printf ("NOBODY WON OMG U BAD + L + RATIO\n");}
}
int main() {
    game();
    return 0;
}
