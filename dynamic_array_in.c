#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    // Allocate memory to variables using calloc(contiguous allocation)
    total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = calloc(total_number_of_shelves, sizeof(int *));
    //Allocate memory to each shelf so that we can use realloc() later
    for(int i=0; i<total_number_of_shelves; i++){
        total_number_of_books[i] = 0;
        total_number_of_pages[i] = (int *)malloc(sizeof(int));
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) { //Insert a book with y pages at the end of the xth shelf.

            int x, y; 
            scanf("%d %d", &x, &y);

            // Using pointer arithmetic
            // *(total_number_of_books + x) += 1;
            // *(total_number_of_pages+x) = realloc(*(total_number_of_pages+x), *(total_number_of_books+x)*sizeof(int));
            // *(*(total_number_of_pages + x) + *(total_number_of_books + x)-1) = y;

            //Using normal Array Accessing
            total_number_of_books[x] += 1;
            total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x]*sizeof(int));
            total_number_of_pages[x][total_number_of_books[x]-1] = y;

        } else if (type_of_query == 2) { //Print the number of pages in the y book on the x shelf.
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y)); 
        } else { //Print the number of books on the x shelf.
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }
    //STOP

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}