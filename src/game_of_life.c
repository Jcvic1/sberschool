#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80

#define ALIVE '*'
#define DEAD ' '

void printField(char field[HEIGHT][WIDTH]);

void getField(char field[HEIGHT][WIDTH]);

void game_over();

int main(int argc, char *argv[]){
    char field[HEIGHT][WIDTH], err = 0;


    getField(field);
    printField(field);
    // game_over();

    return 0;

}



void getField(char field[HEIGHT][WIDTH]) {
    char buff = ' ';
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 1; j++) {
            scanf("%c", &buff);
            if (buff != '\n') {
                field[i][j] = buff;
            }
        }
    }
}

void printField(char field[HEIGHT][WIDTH]) {
    printf("\033c");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            (i == 0 || j == 0 || i == (HEIGHT - 1) || j == (WIDTH - 1)) ? printf("#") : printf("%c", field[i][j]);
        }
        printf("\n");
 
    }
}


void game_over()
{
    for (int i = 0; i < ((HEIGHT / 2) - 1); i++)
    {
        printf("\n");
    }

    for (int j = 0; j < ((WIDTH / 2) - 4.5); j++)
    {
        printf(" ");
    }
    printf("GAME OVER!\n");
}