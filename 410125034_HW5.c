#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 10
#define LETTERS_COUNT 26
#define TARGET_LETTERS 20

int main() {
    srand(time(NULL));

    /* 聲明一個2D'screen'來表示屏幕, +1是為了放置空終止符 */
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1];
    /* 使用空格' '初始化screen，並在每行結尾加上空終止符 */
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = ' ';
        }
        screen[i][SCREEN_WIDTH] = '\0';
    }

    int letter_x[LETTERS_COUNT]; /* 儲存字母的x位置 */
    int letter_y[LETTERS_COUNT]; /* 儲存字母的y位置 */
    char letters[LETTERS_COUNT]; /* 儲存字母 */
    for (int i = 0; i < LETTERS_COUNT; i++) { /* 隨機產生位置及字母 */
        letter_x[i] = rand() % SCREEN_WIDTH;
        letter_y[i] = rand() % SCREEN_HEIGHT;
        letters[i] = 'a' + i;
    }

    int correct = 0, wrong = 0, elapsed_time = 0;
    time_t start_time = time(NULL);
    while (correct < TARGET_LETTERS) { /* 開始循環，直到正確完成20個字母 */
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < SCREEN_WIDTH; j++) {
                screen[i][j] = ' '; /* 通過將所有元素設置為' '，清空screen */
            }
        }

        /* 選擇一個隨機index，將該字母和相應的位置賦值給letter、x和y，並將該字母放置在screen的指定位置 */
        int index;
        do {
            index = rand() % LETTERS_COUNT;
        } while (letters[index] == ' ');
        char letter = letters[index];
        int x = letter_x[index];
        int y = letter_y[index];
        screen[y][x] = letter;

        /* 清除屏幕上的內容，並輸出correct和wrong的值;在屏幕上逐行輸出screen的內容 */
        system("cls");
        printf("correct:%d, wrong:%d\n", correct, wrong);
        printf("----------------------------------------------------\n");
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            printf("|%s|\n", screen[i]);
        }
        printf("----------------------------------------------------\n");

        /* 取得使用者輸入，若輸入字母符合'letter'，則correct +1，反之則wrong +1 */
        int input = getch();
        if (input == letter) {
            correct++;
            letters[index] = ' ';
        } else {
            wrong++;
        }
        /* 計算經過時間並賦值給'elapsed_time' */
        elapsed_time = (int) difftime(time(NULL), start_time);
    }

    /* 清除屏幕上的內容，輸出最終correct和wrong的值與總共使用的秒數 */
    system("cls");
    printf("correct:%d, wrong:%d\n", correct, wrong);
    printf("total time: %.2f seconds\n", (float) elapsed_time);

    return 0;
}

/* THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 陳俞妏 */
