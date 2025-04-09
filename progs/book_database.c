#include <stdio.h>

struct Book {
    int id;
    char title[100];
    char author[50];
};

int main() {
    struct Book books[5];
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Book %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &books[i].id);
        printf("Title: ");
        scanf(" %99[^\n]", books[i].title);
        printf("Author: ");
        scanf(" %49[^\n]", books[i].author);
    }
    printf("\nBook Database:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
    return 0;
}
