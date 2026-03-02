#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50
#define STR_LENGTH 100

 struct Book {
    char name[STR_LENGTH];
    char author[STR_LENGTH];
    char edictor[STR_LENGTH];
    int edition;
};

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

int main(){

    struct Book library[MAX_BOOKS];
    int totalBooks = 0;
    int choice;
    
    do{ 
        printf("=============================================\n");
        printf("\n");   
        printf("Welcome to the Library Management System!\n");
        printf("\n");
        printf("=============================================\n");
        printf("\n");
        printf("1 - Add a new book\n");
        printf("2 -  List all books\n");
        printf("0 - Exit\n");
        printf("\n");
        printf("--------------------------------------------\n");
        printf("Choose one action to begin:\n");


        scanf("%d", &choice);
        cleanBuffer();
        
        switch (choice){
            case 1:
                printf("-------- Adding a new book -------- \n");

                if (totalBooks < MAX_BOOKS) {

                    printf("Enter book name:");
                    fgets(library[totalBooks].name, STR_LENGTH, stdin);
                    printf("Enter book author:");
                    fgets(library[totalBooks].author, STR_LENGTH, stdin);
                    printf("Enter book edictor:");
                    fgets(library[totalBooks].edictor, STR_LENGTH, stdin);
                    printf("Enter book edition:");
                    scanf("%d", &library[totalBooks].edition);
                    cleanBuffer();

                    totalBooks++;

                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full! Cannot add more books.\n");
                }

                printf("\nPress Enter to continue...");
                    getchar();
                    break;
            case 2:
                printf("-------- Listing all books -------- \n");
                if (totalBooks == 0) {
                    printf("No books in the library.\n");
                }
                else {
                    for (int i = 0; i < totalBooks; i++) {
                        printf("--------------------------------------------\n");
                        printf("Book %d:\n", i + 1);
                        printf("Name: %s", library[i].name);
                        printf("Author: %s", library[i].author);
                        printf("Edictor: %s", library[i].edictor);
                        printf("Edition: %d\n", library[i].edition);
                        printf("\n--------------------------------------------\n");

                    }
                }

                 printf("\nPress Enter to continue...");
                    getchar();
                    break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
                printf("\nPress Enter to continue...");
                getchar();
                break;
            }
    } while (choice != 0);
        return 0;

}