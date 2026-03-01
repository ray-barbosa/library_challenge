#include <stdio.h>

typedef struct {
    char name[50];
    char author[50];
    char edictor[50];
    int edition;
} Book;

void main() {
    Book book;
    
    printf("Welcome to the Book Information System!\n");
    printf("Choose one action to begin:\n");
    printf("1. Add a new book\n");
    printf("2. View book details\n");
    printf("3. Exit\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        book = (Book){"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 1};
        break;
    
    default:
        break;
    }

    printf("Hello, World!\n");
    printf("Book edition: %d\n", book.edition);
    return 0;
}