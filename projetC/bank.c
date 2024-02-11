#include <stdio.h>
#include <string.h>
#include "bank.h"


int main(void) {
    displayMenu();
    return 0;
}


void displayMenu(void) {
    int choice;
    Client client;

    do {
        printf("\nMenu:\n");
        printf("1. Créer un client\n");
        printf("2. Afficher les informations du client\n");
        printf("3. Effectuer un dépôt\n");
        printf("4. Effectuer un retrait\n");
        printf("0. Quitter\n");

        printf("Choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                client = createClient();
                break;
            case 2:
                displayClient(&client);
                break;
            case 3: {
                float amount;
                printf("Montant du dépôt: ");
                scanf("%f", &amount);
                deposit(&client, amount);
                break;
            }
            case 4: {
                float amount;
                printf("Montant du retrait: ");
                scanf("%f", &amount);
                withdraw(&client, amount);
                break;
            }
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choice != 0);
}

Client createClient(void) {
    Client newClient;
    printf("Numéro de compte: ");
    scanf("%d", &newClient.accountNumber);

    printf("Nom du client: ");
    scanf("%s", newClient.name);

    newClient.balance = 0.0;

    return newClient;
}
void displayClient(const Client* client) {
    printf("\nInformations du client:\n");
    printf("Numéro de compte: %d\n", client->accountNumber);
    printf("Nom: %s\n", client->name);
    printf("Solde: %.2f\n", client->balance);
}


void deposit(Client* client, float amount) {
    client->balance += amount;
    printf("Dépôt effectué avec succès. Nouveau solde: %.2f\n", client->balance);
}


void withdraw(Client* client, float amount) {
    if (amount <= client->balance) {
        client->balance -= amount;
        printf("Retrait effectué avec succès. Nouveau solde: %.2f\n", client->balance);
    } else {
        printf("Solde insuffisant pour effectuer le retrait.\n");
    }
}
