# Library Management System

A command-line library management system developed in C, featuring a complete system for managing books and tracking loans (empréstimos). This project demonstrates practical application of data structures and dynamic memory allocation in C.

## Overview

This application provides a menu-driven interface to:
- Add new books to the library inventory
- View all available books with their details
- Loan books to users
- Track all active loans

## Features

### 1. **Add New Book** (Option 1)
- Input book details: name, author, publisher (editor), and edition number
- Books are automatically marked as available when added
- Validates library capacity before adding (max 50 books)

### 2. **List All Books** (Option 2)
- Displays complete inventory with:
  - Book number
  - Name
  - Author
  - Publisher
  - Edition
- Shows "No books in the library" if empty

### 3. **Loan Book** (Option 3)
- Lists only available books
- User selects book by number
- Records borrower's name
- Automatically marks book as unavailable
- Validates book availability and selection
- Prevents exceeding maximum loans (100)

### 4. **List All Loans** (Option 4)
- Shows all active loans with:
  - Loan number
  - Borrower name
  - Borrowed book title

## Data Structures

### Book Structure
```c
struct Book {
    char name[100];        // Book title
    char author[100];      // Author name
    char edictor[100];     // Publisher name
    int edition;           // Edition number
    int disponivel;        // Availability flag (1=available, 0=borrowed)
};
```

### Emprestimo (Loan) Structure
```c
struct Emprestimo {
    int indiceLivro;       // Index of borrowed book
    char userName[100];    // Borrower's name
};
```

## Constants

```c
#define MAX_BOOKS 50           // Maximum books in library
#define MAX_EMPRESTIMOS 100    // Maximum active loans
#define STR_LENGTH 100         // String field length
```

## Memory Management

- **Library array**: Dynamically allocated with `calloc()` (zero-initialized)
- **Loans array**: Dynamically allocated with `malloc()`
- Memory validation: Program checks for allocation failures before proceeding
- Proper string handling: Removes trailing newlines from `fgets()` input

## Compilation

Compile using GCC:
```bash
gcc -o main main.c
```

## Running the Program

```bash
./main
```

## Menu Interface

```
=============================================

    Welcome to the Library Management System!

=============================================

1 - Add a new book
2 - List all books
3 - Emprestar livro (Loan book)
4 - Listar emprestimos (List loans)
0 - Exit

--------------------------------------------
Choose one action to begin:
```

## Requirements

- GCC compiler
- Standard C libraries (`stdio.h`, `string.h`, `stdlib.h`)
- Linux/Unix environment (or compatible system)

## Technical Details

### Input Handling
- Uses `scanf()` for numeric input
- Uses `fgets()` for string input (safer than `gets()`)
- Includes `cleanBuffer()` function to clear input buffer after `scanf()`

### Validation
- Library capacity check before adding books
- Loan limit check before creating new loans
- Book availability verification before lending
- Input validation for book selection

## Future Improvements

- [ ] Return/devolution of loaned books
- [ ] Due dates for loans
- [ ] Search functionality for book lookup
- [ ] Edit/delete book information
- [ ] File persistence (save/load library data)
- [ ] User account management
- [ ] Overdue loan tracking
- [ ] Book ratings and reviews

## Author

Academic project from university studies focusing on C data structures.

---

**Language**: C  
**Type**: Educational Project  
**Status**: Feature complete for core functionality
