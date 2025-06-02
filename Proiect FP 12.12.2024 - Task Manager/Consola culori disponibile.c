#include <stdio.h>
void showAllColors() {
    printf("\nCulorile disponibile (0-255):\n");

    // Standard (0-15)
    printf("\Standard (0-15):\n");
    for(int i = 0; i <= 15; i++) {
        printf("\033[48;5;%dm %3d \033[0m", i, i);
        if((i + 1) % 8 == 0) printf("\n");
    }

    // Culori (16-231)
    printf("\nCubul de culori RGB (16-231):\n");
    for(int i = 16; i <= 231; i++) {
        printf("\033[48;5;%dm %3d \033[0m", i, i);
        if((i - 15) % 6 == 0) printf("\n");
    }
    printf("\n");
    // Gri (232-255)
    printf("\Gri (232-255):\n");
    for(int i = 232; i <= 255; i++) {
        printf("\033[48;5;%dm %3d \033[0m", i, i);
        if((i - 231) % 8 == 0) printf("\n");
    }
    printf("\n");
    printf("\033[38;5;196mText rosu aprins\033[0m\n");
    printf("\033[38;5;46mText verde aprins\033[0m\n");
    printf("\033[38;5;21mText albastru aprins\033[0m\n");

    // Fundal
    printf("\033[48;5;196m Text pe fundal rosu aprins \033[0m\n");
    printf("\033[48;5;46m Text pe fundal verde aprins \033[0m\n");
    printf("\033[48;5;21m Text pe fundal albastru aprins \033[0m\n");

    // Combinații text și fundal
    printf("\033[38;5;15;48;5;196m Text alb pe fundal rosu \033[0m\n");
    printf("\033[38;5;0;48;5;46m Text negru pe fundal verde \033[0m\n");
    printf("\033[38;5;15;48;5;21m Text alb pe fundal albastru \033[0m\n");
}

int main() {
    showAllColors();
    return 0;
}
