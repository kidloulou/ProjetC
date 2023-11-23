/*C Exercise
-Define & implement 4 structs & 1 union
-Instantiate 5 structs
-Create 3 function (1 on top of the main() Function, 2 as subprograms)
- Use the main function
 
 idée
  Gestionnaire de tache
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>




#define MAX_TASKS 10

// Union pour stocker des informations spécifiques à la tâche
union TaskInfo {
    int priority;
    char description[50];
};

// Structure pour représenter une tâche
struct Task {
    int id;
    char name[50];
    union TaskInfo info;
    int completed;  // Nouveau champ pour indiquer si la tâche est terminée (1) ou non (0)
};

// Tableau de tâches
struct Task taskList[MAX_TASKS];

// Compteur pour attribuer des identifiants uniques aux tâches
int taskIdCounter = 1;

// Fonction pour ajouter une tâche
void addTask(void) {
    if (taskIdCounter <= MAX_TASKS) {
        struct Task newTask;
        newTask.id = taskIdCounter++;
        
        printf("Nom de la tâche: ");
        scanf("%s", newTask.name);

        printf("1. Tâche avec priorité\n");
        printf("2. Tâche avec description\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Priorité de la tâche: ");
            scanf("%d", &newTask.info.priority);
        } else {
            printf("Description de la tâche: ");
            scanf("%s", newTask.info.description);
        }

        newTask.completed = 0;  // La tâche est initialement non terminée
        taskList[newTask.id - 1] = newTask;
        printf("Tâche ajoutée avec succès.\n");
    } else {
        printf("Limite maximale de tâches atteinte.\n");
    }
}

// Fonction pour afficher toutes les tâches
void displayTasks(void) {
    printf("Liste des tâches :\n");
    for (int i = 0; i < taskIdCounter - 1; ++i) {
        printf("ID: %d, Nom: %s, ", taskList[i].id, taskList[i].name);

        // Affichage des informations spécifiques en fonction du type
        if (taskList[i].info.priority) {
            printf("Priorité: %d\n", taskList[i].info.priority);
        } else {
            printf("Description: %s\n", taskList[i].info.description);
        }

        printf("Statut: %s\n", taskList[i].completed ? "Terminée" : "Non terminée");
    }
}

// Fonction pour marquer une tâche comme terminée
void completeTask(void) {
    int taskId;
    printf("ID de la tâche à marquer comme terminée: ");
    scanf("%d", &taskId);

    if (taskId > 0 && taskId <= taskIdCounter - 1) {
        taskList[taskId - 1].completed = 1;
        printf("Tâche marquée comme terminée.\n");
    } else {
        printf("ID de tâche invalide.\n");
    }
}

int main(void) {
    int choice;

    do {
        // Affichage du menu
        printf("\nMenu :\n");
        printf("1. Créer une tâche\n");
        printf("2. Voir la liste des tâches\n");
        printf("3. Marquer une tâche comme terminée\n");
        printf("4. Quitter le programme\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 4);

    return 0;
}





