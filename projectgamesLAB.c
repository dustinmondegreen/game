#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// PROJECT GAME LAB BE75
// 2702301205 - Muhammad Irham Rizq
// 2702272003 - Antonius William Wijaya
// Judul game : Take a Guess !!

struct Player {
    char name[50];
    int score;
};

int generateRandomNumber() {
    return rand() % 100 + 1;
}

void playNumberGuessingGame(struct Player* player) {
    printf("Selamat datang, %s! Anda memilih Tebak Angka (1-100)!\n", player->name);

    int randomNumber = generateRandomNumber();
    int guess;
    int attempts = 0;

    do {
        printf("Tebak angka: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == randomNumber) {
            printf("Selamat! Anda berhasil menebak angka %d dalam %d percobaan.\n", randomNumber, attempts);
            player->score += 10;
        } else if (guess < randomNumber) {
            printf("Terlalu kecil! Coba lagi.\n");
        } else {
            printf("Terlalu besar! Coba lagi.\n");
        }

    } while (guess != randomNumber);
}

void playWordGuessingGame(struct Player* player) {
    printf("Selamat datang, %s! Anda memilih Tebak Kata!\n", player->name);

    char secretWord[] = "programming";
    char guess[50];
    int attempts = 0;

    printf("Clue: Kata tersebut memiliki %lu huruf.\n", strlen(secretWord));

    do {
        printf("Tebak kata: ");
        scanf("%s", guess);
        attempts++;

        if (strcmp(guess, secretWord) == 0) {
            printf("Selamat! Anda berhasil menebak kata \"%s\" dalam %d percobaan.\n", secretWord, attempts);
            player->score += 15;
        } else {
            if (attempts == 3 || attempts == 6 || attempts == 10) {
                printf("Clue tambahan: ");
                if (attempts == 3) {
                    printf("Huruf pertama: %c\n", secretWord[0]);
                } else if (attempts == 6) {
                    printf("Huruf terakhir: %c\n", secretWord[strlen(secretWord) - 1]);
                } else if (attempts == 10) {
                    printf("Huruf tengah: %c\n", secretWord[strlen(secretWord) / 2]);
                }
            }
            
            printf("Coba lagi!\n");
        }

    } while (strcmp(guess, secretWord) != 0);
}

void displayMenu() {
    printf("Selamat datang di Game Take a Guess !!\n");
    printf("1. Tebak Angka\n");
    printf("2. Tebak Kata\n");
    printf("3. Keluar\n");
}

int main() {
    srand(time(NULL));

    struct Player player;
    printf("Masukkan nama Anda: ");
    scanf("%s", player.name);
    player.score = 0;

    int choice;

    do {
        displayMenu();
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playNumberGuessingGame(&player);
                break;
            case 2:
                playWordGuessingGame(&player);
                break;
            case 3:
                printf("Terima kasih! Keluar dari permainan. Skor Anda: %d\n", player.score);
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }

    } while (choice != 3);

    return 0;
}

