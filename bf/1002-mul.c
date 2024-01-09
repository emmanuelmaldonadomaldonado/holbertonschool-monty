#include <stdio.h>

int main(void) {
    char input[2];
    fgets(input, sizeof(input), stdin);

    int product = (input[0] - '0') * (input[1] - '0');
    printf("%d\n", product % 10);

    return 0;
}
