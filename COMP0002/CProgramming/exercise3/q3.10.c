#include <stdio.h>

int zero(n) {
    if (n == 1 || n == 5) {
        printf("***** ");
    } else {
        printf("*   * ");
    }
    return 0;
}

int one(n) {
    if (n == 1 || n == 3 || n == 4) {
        printf(" *  ");
    } else if (n == 2) {
        printf("**  ");
    } else {
        printf("*** ");
    }
    return 0;
}

int two(n) {
    if (n == 1 || n == 3 || n == 5) {
        printf("****** ");
    } else if (n == 2) {
        printf("     * ");
    } else {
        printf("*      ");
    }
    return 0;
}

int three(n) {
    if (n == 1 || n == 3 || n == 5) {
        printf("****** ");
    } else {
        printf("     * ");
    }
    return 0;
}

int four(n) {
    if (n == 1 || n == 2) {
        printf("*   *  ");
    } else if (n == 3) {
        printf("****** ");
    } else {
        printf("    *  ");
    }
    return 0;
}

int five(n) {
    if (n == 1 || n == 3 || n == 5) {
        printf("****** ");
    } else if (n == 4) {
        printf("     * ");
    } else {
        printf("*      ");
    }
    return 0;
}

int six(n) {
    if (n == 1 || n == 3 || n == 5) {
        printf("****** ");
    } else if (n == 2) {
        printf("*      ");
    } else {
        printf("*    * ");
    }
    return 0;
}

int seven(n) {
    if (n == 1) {
        printf("***** ");
    } else {
        printf("    * ");
    }
    return 0;
}

int eight(n) {
    if (n == 2 || n == 4) {
        printf("*    * ");
    } else {
        printf("****** ");
    }
    return 0;
}

int nine(n) {
    if (n == 1 || n == 3) {
        printf("***** ");
    } else if (n == 2) {
        printf("*   * ");
    } else {
        printf("    * ");
    }
    return 0;
}

int main(void) {
    //Get input numbers

    //Print out the numbers
    int i, column;
    for (i=1;i<=5;i++) {
        one(i);
        eight(i);
        nine(i);
        printf("\n");
    }
    return 0;
}