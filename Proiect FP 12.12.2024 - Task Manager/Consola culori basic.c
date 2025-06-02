#include <stdio.h>
// Coduri pentru culori text
#define BLACK "\033[30m"
#define RED "\033[31m"
#define LIGHT_ORANGE "\033[38;5;215m"    // Portocaliu deschis
#define DARK_ORANGE "\033[38;5;208m"     // Portocaliu închis
#define ORANGE1 "\033[38;5;214m"         // Portocaliu auriu
#define ORANGE2 "\033[38;5;172m"         // Portocaliu maro
#define ORANGE3 "\033[38;5;166m"         // Portocaliu intens
#define ORANGE4 "\033[38;5;130m"         // Portocaliu închis spre maro
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define PINK1 "\033[38;2;255;192;203m"   // Light Pink
#define PINK2 "\033[38;2;255;182;193m"   // Light Pink 2
#define PINK3 "\033[38;2;255;162;173m"   // Medium Pink
#define PINK4 "\033[38;2;255;142;153m"   // Dark Pink
#define PINK5 "\033[38;2;255;122;133m"   // Deep Pink
#define PINK6 "\033[38;2;255;102;113m"   // Hot Pink
#define PINK7 "\033[38;2;255;82;93m"     // Bright Pink
#define PINK8 "\033[38;2;255;62;73m"     // Strong Pink
#define PINK9 "\033[38;2;255;42;53m"     // Vibrant Pink
#define PINK10 "\033[38;2;255;22;33m"    // Intense Pink

// Culori bold/bright
#define BRIGHT_BLACK "\033[1;30m"
#define BRIGHT_RED "\033[1;31m"
#define BRIGHT_GREEN "\033[1;32m"
#define BRIGHT_YELLOW "\033[1;33m"
#define BRIGHT_BLUE "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN "\033[1;36m"
#define BRIGHT_WHITE "\033[1;37m"

// Culori fundal
#define BLACK_BG "\033[40m"
#define RED_BG "\033[41m"
#define GREEN_BG "\033[42m"
#define YELLOW_BG "\033[43m"
#define BLUE_BG "\033[44m"
#define MAGENTA_BG "\033[45m"
#define CYAN_BG "\033[46m"
#define WHITE_BG "\033[47m"

// Culori bright fundal
#define BG_BRIGHT_BLACK "\033[100m"
#define BG_BRIGHT_RED "\033[101m"
#define BG_BRIGHT_GREEN "\033[102m"
#define BG_BRIGHT_YELLOW "\033[103m"
#define BG_BRIGHT_BLUE "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN "\033[106m"
#define BG_BRIGHT_WHITE "\033[107m"

// Culori underline
#define UNDERLINE_BLACK "\033[4;30m"
#define UNDERLINE_RED "\033[4;31m"
#define UNDERLINE_GREEN "\033[4;32m"
#define UNDERLINE_YELLOW "\033[4;33m"
#define UNDERLINE_BLUE "\033[4;34m"
#define UNDERLINE_MAGENTA "\033[4;35m"
#define UNDERLINE_CYAN "\033[4;36m"
#define UNDERLINE_WHITE "\033[4;37m"

// Stiluri speciale
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define INVERSE "\033[7m"
#define BOLD_OFF "\033[21m"
#define UNDERLINE_OFF "\033[24m"
#define INVERSE_OFF "\033[27m"
#define RESET "\033[0m"

// Cod pentru resetare culori
#define RESET_COLOR "\033[0m"

int main() {
   // Demo culori normale
    printf("Culori normale text:");
    printf("%sText Negru%s\n", BLACK, RESET);
    printf("%sText Rosu%s\n", RED, RESET);
    printf("%sText Verde%s\n", GREEN, RESET);
    printf("%sText Galben%s\n", YELLOW, RESET);
    printf("%sText Albastru%s\n", BLUE, RESET);
    printf("%sText Magenta%s\n", MAGENTA, RESET);
    printf("%sText Cyan%s\n", CYAN, RESET);
    printf("%sText Alb%s\n", WHITE, RESET);

    // Demo culori bright
    printf("\nCulori bright text:\n");
    printf("%sText Negru Bright%s\n", BRIGHT_BLACK, RESET);
    printf("%sText Rosu Bright%s\n", BRIGHT_RED, RESET);
    printf("%sText Verde Bright%s\n", BRIGHT_GREEN, RESET);
    printf("%sText Galben Bright%s\n", BRIGHT_YELLOW, RESET);
    printf("%sText Albastru Bright%s\n", BRIGHT_BLUE, RESET);
    printf("%sText Magenta Bright%s\n", BRIGHT_MAGENTA, RESET);
    printf("%sText Cyan Bright%s\n", BRIGHT_CYAN, RESET);
    printf("%sText Alb Bright%s\n", BRIGHT_WHITE, RESET);

    // Demo culori underline
    printf("\nCulori cu underline:\n");
    printf("%sText Subliniat Rosu%s\n", UNDERLINE_RED, RESET);
    printf("%sText Subliniat Verde%s\n", UNDERLINE_GREEN, RESET);
    printf("%sText Subliniat Albastru%s\n", UNDERLINE_BLUE, RESET);

    // Demo background colors
    printf("\nCulori de background:\n");
    printf("%s Text pe fundal rosu %s\n", RED_BG, RESET);
    printf("%s Text pe fundal verde %s\n", GREEN_BG, RESET);
    printf("%s Text pe fundal albastru %s\n", BLUE_BG, RESET);

    // Demo bright background colors
    printf("\nCulori bright de background:\n");
    printf("%s Text pe fundal rosu bright %s\n", BG_BRIGHT_RED, RESET);
    printf("%s Text pe fundal verde bright %s\n", BG_BRIGHT_GREEN, RESET);
    printf("%s Text pe fundal albastru bright %s\n", BG_BRIGHT_BLUE, RESET);

    // Demo stiluri combinate
    printf("\nCombinatii de stiluri:\n");
    printf("%s%sText rosu bold%s\n", BOLD, RED, RESET);
    printf("%s%sText verde subliniat%s\n", UNDERLINE, GREEN, RESET);
    printf("%s%s%sText albastru bold si subliniat%s\n", BOLD, UNDERLINE, BLUE, RESET);
    printf("%s%s%sText rosu pe fundal galben%s\n", RED, YELLOW_BG, BOLD, RESET);

    return 0;
}
