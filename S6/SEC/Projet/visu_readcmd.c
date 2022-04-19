// Visualisation des résultats de readcmd [ZH, le 7/5/21]

#include <stdio.h>
#include <stdlib.h>
#include "readcmd.h"

int main() {
    int index;
    struct cmdline *commande;
    printf("==== Visualisation des résultats de readcmd(). Ctrl-C pour finir ===== \n\n");
    do {
        printf("Entrez votre commande>>> ");
        commande = readcmd();

        if (commande == NULL) {
            printf("\n--- Erreur da la fonction de saisie ou EOF - CtrlD\n");
        }
        else {
            if (commande->err != NULL) {
                /* tous les autres champs de commande sont NULL */
                printf("--- Erreur de structure de la commande : %s\n", commande->err);
            }

            else {
                if (commande->in != NULL) {
                    printf("=== Redirection de l'entrée : %s\n", commande->in);
                }
                if (commande->out != NULL) {
                    printf("=== Redirection de la sortie : %s\n", commande->out);
                }
                if (commande->backgrounded != NULL) {
                    printf("=== Commande en tache de fond\n");
                }
                /* commande->seq[i] est accessible seulement si :
                	commande != NULL && command->err == NULL
                */
                if (commande->seq[0] == NULL) {
                    printf("=== Commande vide\n");
                }
                else {
                    index = 0;
                    while (commande->seq[index] != NULL) {
                        printf("   Commande %d : %s\n", index, commande->seq[index][0]);
                        index++;
                    }
                }
            }
        }
    } while(1);
}

