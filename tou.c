#include <stdio.h>

#define MAX_PROCESSES 100

// Structure pour représenter un processus
typedef struct {
    int id;             // Identifiant du processus
    int burstTime;      // Temps d'exécution
    int remainingTime; // Temps restant d'exécution
} Process;

int main() {
    int n; // Nombre de processus
    int quantum = 2; // Taille de la quantité (quantum)
    Process processes[MAX_PROCESSES]; // Liste des processus

    // Lecture du nombre de processus depuis l'utilisateur
    printf("Entrez le nombre de processus: ");
    scanf("%d", &n);

    // Lecture des données de chaque processus depuis l'utilisateur
    for (int i = 0; i < n; i++) {
        printf("Entrez le temps d'execution du processus %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int currentTime = 0; // Temps actuel du système
    int completedProcesses = 0; // Nombre de processus terminés

    // Début de l'exécution des processus
    printf("\nDébut de l'execution des processus:\n");
    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                // Exécution du processus avec la quantité spécifiée
                printf("Processus %d: Execution pendant %d unites de temps\n", processes[i].id, quantum);
                currentTime += quantum;
                processes[i].remainingTime -= quantum;

                // Si le processus est terminé, imprimer un message de fin et incrémenter le nombre de processus terminés
                if (processes[i].remainingTime <= 0) {
                    printf("Processus %d: --------------------|Termine| apres %d unites de temps\n", processes[i].id, currentTime);
                    completedProcesses++;
                }
            }
        }
    }

    return 0;
}
