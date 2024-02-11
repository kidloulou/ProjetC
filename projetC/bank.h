#ifndef BANK_H
#define BANK_H


typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Client;


void displayMenu(void);
Client createClient(void);
void displayClient(const Client* client);
void deposit(Client* client, float amount);
void withdraw(Client* client, float amount);

#endif // BANK_H
