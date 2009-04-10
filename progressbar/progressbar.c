#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define len         50

typedef struct data_type {
    char spaces[len];
} data;

static void fwheel(int j) {
    char wheel[5] = "\\|/-";

    printf("\t");
    printf("%c ", wheel[j%4]);
}

static void fprogress() {
    data *progressbar;
    progressbar = (data*) malloc(sizeof(data));

    memset(progressbar->spaces, ' ', len);
    progressbar->spaces[0] = '[';
    progressbar->spaces[len - 2] = ']';
    progressbar->spaces[len - 1] = '\0';

    printf("%s", progressbar->spaces);

    int i;
    for(i = 1; i < len - 2; i++) {
        progressbar->spaces[i] = '=';
        printf("\r%s", progressbar->spaces);
        fwheel(i);

        usleep(40000);
        fflush(stdout);
    }

    free(progressbar);
}

int main(void) {
    fprogress();

    printf("\b\bDone.\n");
    return 0;
}
