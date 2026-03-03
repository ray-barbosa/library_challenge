#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BOOKS 50
#define MAX_EMPRESTIMOS 100
#define STR_LENGTH 100

 struct Book {
    char name[STR_LENGTH];
    char author[STR_LENGTH];
    char edictor[STR_LENGTH];
    int edition;
    int disponivel;

};

struct Emprestimo {
    int indiceLivro;
    char userName[STR_LENGTH];
};

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

int main(){

    struct Book *library;
    struct Emprestimo *emprestimos;


    library = (struct Book *) calloc(MAX_BOOKS, sizeof(struct Book));

    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));
    
    if(library == NULL || emprestimos == NULL){
        printf("ERRO: Falha ao alocar memória.\n");
        return 1;
    }

    int totalBooks = 0;
    int totalEmprestimos = 0;
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
        printf("3 - Emprestar livro\n");
        printf("4 - Listar emprestimos\n");
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

                    /* strip trailing newline from fgets using strcspn */
                    library[totalBooks].name[strcspn(library[totalBooks].name, "\n")] = '\0';
                    library[totalBooks].author[strcspn(library[totalBooks].author, "\n")] = '\0';
                    library[totalBooks].edictor[strcspn(library[totalBooks].edictor, "\n")] = '\0';
                    /* mark book as available */
                    library[totalBooks].disponivel = 1;
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
                        printf("Book: %d\n", i + 1);
                        printf("Name: %s\n", library[i].name);
                        printf("Author: %s\n", library[i].author);
                        printf("Edictor: %s\n", library[i].edictor);
                        printf("Edition: %d\n", library[i].edition);
                        printf("\n--------------------------------------------\n");

                    }
                }

                 printf("\nPress Enter to continue...");
                    getchar();
                    break;
            case 3:
                printf("-------- Emprestar livro -------- \n");

                if (totalEmprestimos >= MAX_EMPRESTIMOS){
                    printf("Numero maximo de emprestimos atingido!\n");
                } else {
                    int disponiveis = 0;
                    for(int i = 0; i < totalBooks; i++){
                        if(library[i].disponivel){
                            printf("%d - %s\n", i + 1, library[i].name);
                            disponiveis++;
                        }
                    }
                    if (disponiveis == 0){
                        printf("Nenhum livro disponivel para emprestimo!\n");
                    } else {
                        printf("Escolha o numero do livro que deseja emprestar:\n");
                        int numLivro;
                        scanf("%d", &numLivro);
                        cleanBuffer();

                        int indexLivro = numLivro - 1;

                    if(indexLivro >= 0 && indexLivro < totalBooks && library[indexLivro].disponivel){
                        printf("Digite seu nome para o emprestimo:\n");
                        fgets(emprestimos[totalEmprestimos].userName, STR_LENGTH, stdin);
                        emprestimos[totalEmprestimos].userName[strcspn(emprestimos[totalEmprestimos].userName, "\n")] = '\0';

                        emprestimos[totalEmprestimos].indiceLivro = indexLivro;

                        library[indexLivro].disponivel = 0;

                        totalEmprestimos++;
                        
                        printf("Emprestimo realizado com sucesso!\n");
                    } else {
                        printf("Livro indisponivel ou numero invalido!\n");
                    }
                }
            }
                printf("\nPress Enter to continue...");
                getchar();
                break;
            case 4:
                printf("-------- Listar emprestimos -------- \n");
                if (totalEmprestimos == 0){
                    printf("Nenhum emprestimo registrado!\n");
                } else {
                    for (int i = 0; i < totalEmprestimos; i++){
                        int indexLivro = emprestimos[i].indiceLivro;
                        printf("--------------------------------------------\n");
                        printf("Emprestimo: %d\n", i + 1);
                        printf("User: %s\n", emprestimos[i].userName);
                        printf("Book: %s\n", library[indexLivro].name);
                        printf("--------------------------------------------\n");
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