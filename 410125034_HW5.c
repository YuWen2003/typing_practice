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

    /* �n���@��2D'screen'�Ӫ�ܫ̹�, +1�O���F��m�Ųפ�� */
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH + 1];
    /* �ϥΪŮ�' '��l��screen�A�æb�C�浲���[�W�Ųפ�� */
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen[i][j] = ' ';
        }
        screen[i][SCREEN_WIDTH] = '\0';
    }

    int letter_x[LETTERS_COUNT]; /* �x�s�r����x��m */
    int letter_y[LETTERS_COUNT]; /* �x�s�r����y��m */
    char letters[LETTERS_COUNT]; /* �x�s�r�� */
    for (int i = 0; i < LETTERS_COUNT; i++) { /* �H�����ͦ�m�Φr�� */
        letter_x[i] = rand() % SCREEN_WIDTH;
        letter_y[i] = rand() % SCREEN_HEIGHT;
        letters[i] = 'a' + i;
    }

    int correct = 0, wrong = 0, elapsed_time = 0;
    time_t start_time = time(NULL);
    while (correct < TARGET_LETTERS) { /* �}�l�`���A���쥿�T����20�Ӧr�� */
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            for (int j = 0; j < SCREEN_WIDTH; j++) {
                screen[i][j] = ' '; /* �q�L�N�Ҧ������]�m��' '�A�M��screen */
            }
        }

        /* ��ܤ@���H��index�A�N�Ӧr���M��������m��ȵ�letter�Bx�My�A�ñN�Ӧr����m�bscreen�����w��m */
        int index;
        do {
            index = rand() % LETTERS_COUNT;
        } while (letters[index] == ' ');
        char letter = letters[index];
        int x = letter_x[index];
        int y = letter_y[index];
        screen[y][x] = letter;

        /* �M���̹��W�����e�A�ÿ�Xcorrect�Mwrong����;�b�̹��W�v���Xscreen�����e */
        system("cls");
        printf("correct:%d, wrong:%d\n", correct, wrong);
        printf("----------------------------------------------------\n");
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            printf("|%s|\n", screen[i]);
        }
        printf("----------------------------------------------------\n");

        /* ���o�ϥΪ̿�J�A�Y��J�r���ŦX'letter'�A�hcorrect +1�A�Ϥ��hwrong +1 */
        int input = getch();
        if (input == letter) {
            correct++;
            letters[index] = ' ';
        } else {
            wrong++;
        }
        /* �p��g�L�ɶ��ý�ȵ�'elapsed_time' */
        elapsed_time = (int) difftime(time(NULL), start_time);
    }

    /* �M���̹��W�����e�A��X�̲�correct�Mwrong���ȻP�`�@�ϥΪ���� */
    system("cls");
    printf("correct:%d, wrong:%d\n", correct, wrong);
    printf("total time: %.2f seconds\n", (float) elapsed_time);

    return 0;
}

/* THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 ���\ʹ */
