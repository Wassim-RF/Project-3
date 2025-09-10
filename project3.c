#include <stdio.h>
#include <string.h>

#define MAX_U 100

int main() {
    char utilisateur[MAX_U];

    while (1) {
        printf("UTILISATEUR : ");
        fgets(utilisateur , MAX_U , stdin);
        utilisateur[strcspn(utilisateur , "\n")] = '\0';
        if (strcmp(utilisateur, "exit") == 0) {
            printf("ChatBot : Au revoir\n");
            break;
        }
        int found = 0;
        char botReply[MAX_U] = "Je ne comprends pas...";
    }
}