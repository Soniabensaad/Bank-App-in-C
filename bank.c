#include <stdio.h>
#include <stdlib.h>
#define CMAX 15
int choice, x ;

typedef struct Client
{
    int Code_cli;
    char First_Name[CMAX];
    char Name[CMAX];
}Client;

int compare(const void* a, const* b)
{
    const Client *c1 = a;
    const Client *c2 = b;
    return strcmp(c1->First_Name, c2->First_Name);
}

typedef struct Date
{
    int Day;
    int Month;
    int Year;
}Date;

typedef struct Account
{
    int Code_act;
    int Code_cli;
    struct Date d_account;
}Account;

Client clients[20];
Account Accounts[20];


void menu()
{
    printf("1- Manage clients\n");
    printf("2- Manage accounts\n");
    printf("3- Manage oprations\n");
    printf("4- exit program\n");
    printf("choice of menu :");
    scanf("%d", &choice);
    sub_menu(choice);
}
void sub_menu(int a)
{
    if (a == 1)
    {
        printf("1- insert client\n");
        printf("2- modify client\n");
        printf("3- delete client\n");
        printf("4- show list of clients in order\n");
        printf("5- return\n"); // retour au menu
        printf("choice of sub menu : \n");
        scanf("%d", &x);
        manage_clients(x);
    }
     else if (a == 2)
    {
        printf("1- insert account\n");
        printf("2- search account\n"); //rechercher un compte via son numéro
        printf("3- show accounts\n"); // Afficher la liste des comptes par ordre alphabétique
        printf("4- delete account\n");
        printf("5- return\n"); // retour au menu
        printf("choice of sub menu : \n");
        scanf("%d", &x);
        manage_accounts(x);
    }

    else if (a == 3)
    {
        printf("1- money withdrawal\n"); //retrait d'argent
        printf("2- show after operation\n"); // afficher les infos du compte après opérations
        printf("choice of sub menu : \n");
        scanf("%d", &x);
        //manage_operations(x);
    }

    
    else if (a == 4)
    {
        return 0;
    }
    else
    {
        printf("incorrect choice\n");
        return 0;
    }
}

manage_clients(int a)
{
    if (a == 1)
    {
        struct Client client;
        FILE *file;
        printf("Code client : ");
        scanf("%d", &client.Code_cli);
        printf("First name : ");
        scanf("%s", &client.First_Name);
        printf("Name : ");
        scanf("%s", &client.Name);
        file = fopen("client.txt", "a");
        fwrite(&client, sizeof(client), 1, file);
        if (fwrite != 0)
        {
            printf("customer added successfully");
        }
        else
        {
            printf("Error");
        }
        
        fclose(file);
    }
    else if (a == 2)
    {
        struct Client client;
        struct Client new_client;
        FILE *file;
        printf("Code client to modify : ");
        scanf("%d", &new_client.Code_cli);
        printf("new first name : ");
        scanf("%s", &new_client.First_Name);
        printf("new name : ");
        scanf("%s", &new_client.Name);

        file = fopen("client.txt", "r");
        int n_clients = 0;
        while (fread(&client, sizeof(struct Client), 1, file))
        {
            clients[n_clients] = client;
            n_clients++;
        }
        fclose(file);
        remove("client.txt");
        
        FILE *new;
        new = fopen("new.txt", "a");
        for (int i = 0; i < n_clients; i++)
        {
            if (clients[i].Code_cli = new_client.Code_cli)
            {
                fwrite(&new_client, sizeof(clients[i]), 1, new);
            }
            else
            {
                fwrite(&clients[i], sizeof(clients[i]), 1, new);
            }
        }
        fclose(new);
        rename("new.txt", "client.txt");


    }
    else if (a == 3)
    {
        struct Client client;
        int Code;
        FILE *file;
        printf("Code client to delete : ");
        scanf("%d", &Code);

        file = fopen("client.txt", "r");
        int n_clients = 0;
        while (fread(&client, sizeof(struct Client), 1, file))
        {
            clients[n_clients] = client;
            n_clients++;
        }
        fclose(file);
        remove("client.txt");
        
        FILE *new;
        new = fopen("new.txt", "a");
        for (int i = 0; i < n_clients; i++)
        {
            if (clients[i].Code_cli != Code)
            {
                fwrite(&clients[i], sizeof(clients[i]), 1, new);
            }
            else if (clients[i].Code_cli = 0)
            {
                printf("No More Clients");
            }
            else
            {
                printf("Error");
            }
        }
        fclose(new);
        rename("new.txt", "client.txt");

    }
    
    else if (a == 4)
    {
        FILE *file;
        struct Client client;
        file = fopen ("client.txt", "r");
        int n_clients = 0;
        while (fread(&client, sizeof(struct Client), 1, file))
        {
            clients[n_clients] = client;
            n_clients++;
        }
        fclose(file);
        qsort(clients, n_clients, sizeof(Client), compare);
        for (int i = 0; i < n_clients; i++)
        {
            printf("\nCode client : %d", clients[i].Code_cli);
            printf("\nFirst Name  %s %s", clients[i].First_Name, clients[i].Name);
            printf("\n");
        }
        
    }
    else if (a == 5)
    {
        menu();
    }
}

void manage_accounts(a)
{
    if (a == 1)
    {
        
        struct Account account;
        FILE *file;
        printf("Code account : ");
        scanf("%d", &account.Code_act);
        printf("Code client : ");
        scanf("%d", &account.Code_cli);
        printf("Day : ");
        scanf("%d", &account.d_account.Day);
        printf("Month : ");
        scanf("%d", &account.d_account.Month);
        printf("Year : ");
        scanf("%d", &account.d_account.Year);

        file = fopen("account.txt", "a");
        fwrite(&account, sizeof(account), 1, file);
        if (fwrite != 0)
        {
            printf("account added successfully");
        }
        else
        {
            printf("Error");
        }
        
        fclose(file);
    }
    

}
int main()
{
    menu();
    return 0;
}
