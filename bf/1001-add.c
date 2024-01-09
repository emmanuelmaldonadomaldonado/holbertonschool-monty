#include <stdio.h>

int main(void) {
    char input[2];
    fgets(input, sizeof(input), stdin);

    int sum = (input[0] - '0') + (input[1] - '0');
    printf("%d\n", sum % 10);

    return 0;
}

