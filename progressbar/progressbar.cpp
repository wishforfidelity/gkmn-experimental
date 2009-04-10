#include <iostream>
#include <string>

#define len     50
using namespace std;

static char fWheel(int digit) {
    char wheel[5] = "\\|/-";

    return wheel[digit%4];
}

static string fSpaces(int digit, int tour) {
    string spaces;
    spaces.append("\r[");
    spaces.append(digit, '=');
    spaces.append(tour - digit - 3, ' ');
    spaces.append("]");

    return spaces;
}

static void fProgress(int digit) {
    for(digit = 1; digit < len - 2; digit++) {
        cout << fSpaces(digit, len) << '\t' << fWheel(digit) << ' ';

        usleep(40000);
        fflush(stdout);
    }
}

int main(void) {
    fProgress(len);

    cout << "\b\bDone.\n";
}
