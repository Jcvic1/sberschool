#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80

#define ALIVE '*'
#define DEAD ' '

void printField(int field[HEIGHT][WIDTH]);

void getField(int field[HEIGHT][WIDTH], FILE *file);

void game_over();

int main(int argc, char *argv[]){
    int field[HEIGHT][WIDTH], err = 0;
    FILE *file;

    if(argc != 2){
        printf("Argument missing, pass file name as arguement.\n");
        err = 1;
    }

    if (!err) {
        if (!(file = fopen(argv[1], "r"))) {
            printf("Error opening file.\n");
            err = 1;
        }
    }

    if (!err) {

        getField(field, file);
        printField(field);
        fclose(file);
        // game_over();

    }
    return 0;

}



void getField(int field[HEIGHT][WIDTH], FILE *file) {
    char buff = ' ';
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 1; j++) {
            fscanf(file, "%c", &buff);
            if (buff != '\n') {
                field[i][j] = buff;
            }
        }
    }
}

void printField(int field[HEIGHT][WIDTH]) {
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