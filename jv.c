#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    char command[100];
    sprintf(command, "javac %s.java && java %s", argv[1], argv[1]);
    system(command);
    return 0;
}