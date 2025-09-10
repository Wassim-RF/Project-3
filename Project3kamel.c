#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define HISTO_SIZE 100

int main() {
    char input[MAX];
    char *positifs[] = {"happy", "bien", "cool"};
    char *negatifs[] = {"sad", "triste", "mauvais"};
    char *neutres[]  = {"bonjour", "salut", "hello"};
    char *reponsesPos[] = {"Super !", "Genial d'entendre ça !", "Top"};
    char *reponsesNeg[] = {"Oh courage...", "Ne t'inquiete pas ca va aller.", "Desole d'entendre ca."};
    char *reponsesNeu[] = {"Salut ", "Hey !", "Bonjour "};

    int nbPos = sizeof(positifs) / sizeof(positifs[0]);
    int nbNeg = sizeof(negatifs) / sizeof(negatifs[0]);
    int nbNeu = sizeof(neutres)  / sizeof(neutres[0]);

    srand(time(NULL)); 

    while (1) {
        printf("\nUtilisateur : ");
        fgets(input, MAX, stdin);
        input[strcspn(input, "\n")] = 0; 

        if (strcmp(input, "exit") == 0) {
            printf("ChatBot : Au revoir\n");
            break;
        }
        int found = 0;
        char botReply[MAX] = "Je ne comprends pas...";
        for (int i = 0; i < nbPos; i++) {
            if (strstr(input, positifs[i]) != NULL) {
                strcpy(botReply, reponsesPos[rand() % 3]);
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < nbNeg; i++) {
                if (strstr(input, negatifs[i]) != NULL) {
                    strcpy(botReply, reponsesNeg[rand() % 3]);
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            for (int i = 0; i < nbNeu; i++) {
                if (strstr(input, neutres[i]) != NULL) {
                    strcpy(botReply, reponsesNeu[rand() % 3]);
                    found = 1;
                    break;
                }
            }
        }
        printf("ChatBot : %s\n", botReply);
    }
    return 0;
}
