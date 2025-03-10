#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Library
struct library {
    char book_name[50];
    char author[50];
    int pages;
    float price;
};

// Driver Code
int main() {
    struct library lib[100];
    char ar_nm[50], bk_nm[50];
    int i, input, count = 0;

    while (1) {
        printf("\n\n********###### WELCOME TO E-LIBRARY #####********\n");
        printf("1. Add book information\n");
        printf("2. Display book information\n");
        printf("3. List all books of a given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Exit\n");

        printf("\nEnter one of the above options: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Enter book name: ");
                scanf(" %[^"]s", lib[count].book_name);

                printf("Enter author name: ");
                scanf(" %[^"]s", lib[count].author);

                printf("Enter number of pages: ");
                scanf("%d", &lib[count].pages);

                printf("Enter price: ");
                scanf("%f", &lib[count].price);

                count++;
                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No books available in the library.\n");
                } else {
                    printf("\nBook Information:\n");
                    for (i = 0; i < count; i++) {
                        printf("Book Name: %s\n", lib[i].book_name);
                        printf("Author Name: %s\n", lib[i].author);
                        printf("Pages: %d\n", lib[i].pages);
                        printf("Price: %.2f\n", lib[i].price);
                        printf("---------------------------------\n");
                    }
                }
                break;

            case 3:
                printf("Enter author name: ");
                scanf(" %[^"]s", ar_nm);

                int found = 0;
                for (i = 0; i < count; i++) {
                    if (strcmp(ar_nm, lib[i].author) == 0) {
                        printf("%s by %s, Pages: %d, Price: %.2f\n",
                               lib[i].book_name, lib[i].author, lib[i].pages, lib[i].price);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No books found by author '%s'.\n", ar_nm);
                }
                break;

            case 4:
                printf("\nTotal number of books in the library: %d\n", count);
                break;

            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
                
            default:
                printf("Invalid input! Please choose a valid option.\n");
        }
    }

    return 0;
}
