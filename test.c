#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8
#define UP 8
#define DOWN 2
#define LEFT 4
#define RIGHT 6
#define BLOCK 'X'
#define DIE '*'
#define TREASURE 'T'
#define PERSON 'P'

void initialize_map(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '.';
        }
    }

    // Place the player at the starting position
    map[0][0] = PERSON;

    // Place the treasure at a fixed position (you can change this)
    map[ROWS - 1][COLS - 1] = TREASURE;

    // Randomly place blocks and death tiles
    srand(time(NULL));
    int num_blocks = 5; // Adjust the number of blocks as needed
    int num_death_tiles = 1; // Adjust the number of death tiles as needed

    while (num_blocks > 0) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (map[row][col] == '.') {
            map[row][col] = BLOCK;
            num_blocks--;
        }
    }

    while (num_death_tiles > 0) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (map[row][col] == '.') {
            map[row][col] = DIE;
            num_death_tiles--;
        }
    }
}

void print_map(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
	printf("ADVETURE GAME\n");
	printf("-------------\n");
    char map[ROWS][COLS];
    initialize_map(map);

    int player_row = 0, player_col = 0;

    while (1) {
	printf("\n\n");
        print_map(map);
    printf("UP %d\n", UP);
    printf("DOWN %d\n", DOWN);
    printf("LEFT %d\n", LEFT);
    printf("RIGHT %d\n", RIGHT);
    printf("BLOCK '%c'\n", BLOCK);
    printf("DIE '%c'\n", DIE);
    printf("TREASURE '%c'\n", TREASURE);
    printf("PERSON '%c'\n\n\n", PERSON);
        printf("Enter your move: ");
        int move;
        scanf("%d", &move);

        int newRow = player_row;
        int newCol = player_col;

        switch (move) {
            case UP:
                newRow--;
                break;
            case DOWN:
                newRow++;
                break;
            case LEFT:
                newCol--;
                break;
            case RIGHT:
                newCol++;
                break;
            default:
                printf("Invalid move.\n");
                continue;
        }

        if (newRow < 0 || newRow >= 10 || newCol < 0 || newCol >= 10) {
            printf("Out of bounds.\n");

            continue;
        }

        if (map[newRow][newCol] == BLOCK) {
            printf("BLOCKED\n");
            continue;
        }

        if (map[newRow][newCol] == DIE) {
            printf("You died!\n");
            break;
        }

        if (map[newRow][newCol] == TREASURE) {
            printf("You won!\n");
            break;
        }

        map[player_row][player_col] = '.';
        map[newRow][newCol] = PERSON;
        player_row = newRow;
        player_col = newCol;
    }

    return 0;
}