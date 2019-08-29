#include <stdio.h>

int main(void) {

    const char *sharks[9] = { "baby", "mommy", "daddy", "grandma",
        "grandpa", "let's go hunt", "run away", "safe at last",
        "it's the end"
    };

    char * is_shark = " shark";
    int i, j;
    for (i = 0; i < 9; i++) {
        if (i == 5)
            is_shark = "";
        for (j = 0; j < 3; j++) {
            printf("%s%s, doo doo doo doo doo doo\n", sharks[i], is_shark);
        }
        printf("%s%s\n\n", sharks[i], is_shark);
    }

    return 0;
}
