#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void compileJava(char** argv);

int main(int argc, char** argv) {
    char command[100];
    if (strcmp(argv[1], "-c") == 0) {
        compileJava(argv);
    } else {
        sprintf(command, "javac %s.java && java %s", argv[1], argv[1]);
        system(command);
    }
    return 0;
}

void compileJava(char** argv) {
    char comand_mkdir[100];
    char comand_compile[100];
    char comand_jar[100];

    sprintf(comand_mkdir, "mkdir temp");
    sprintf(comand_compile, "javac -d temp -cp . *.java %s.java", argv[2]);
    sprintf(comand_jar, "jar cvfm %s.jar manifest.mf -C temp .", argv[3]);

    system(comand_mkdir);
    system(comand_compile);
    system(comand_jar);
}