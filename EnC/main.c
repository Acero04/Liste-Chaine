#include "List.h"
#include <stdio.h>

int main () {
    List* MyList = create_list();

    insert(MyList, 8.50);
    insert(MyList, 89.50);
    insert(MyList, 34.29);
    insert(MyList, 75.21);

    display_list(MyList);


    printf("\n\n");

    if (search_value(MyList, 8.50)) {
        printf("Element trouver.\n");
    } else {
        printf("Element non trouver.\n");
    }

    delete_node(MyList, 89.5);
    display_list(MyList);

    delete_list(MyList);

    return 0;
}
