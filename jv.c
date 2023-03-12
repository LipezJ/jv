#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#define SEPARATOR "\\"
#else
#define SEPARATOR "/"
#endif

void compileJava(char** argv);
void createDir(char *fileName);
void compile(char *classFile);

int main(int argc, char** argv) {
    char command[100];
    if (strcmp(argv[1], "-j") == 0 && argc == 4) {
        compileJava(argv);
    } else if (strcmp(argv[1], "-c") == 0 && argc == 3) {
        compile(argv[2]);
    } else if (argc == 2) {
        createDir("temp");
        compile(argv[1]);
        sprintf(command, "java -cp temp %s", argv[1]);
        system(command);
    } else {
        printf("use:\n\tjv [-c -j] <Class name> <Jar name> [-m] <Manifest path>\n\n");
        printf("-j -> compile the code in the temp folder and generate the .jar executable\n");
        printf("-c -> compile the code in the temp folder\n");
    }
    return 0;
}

void compileJava(char** argv) {
    char comand_jar[100];
    createDir("temp");
    compile(argv[2]);
    sprintf(comand_jar, "jar cvfm build%s%s.jar manifest.mf -C temp .", SEPARATOR, argv[3]);
    system(comand_jar);
}

void compile(char *classFile) {
    char comand_compile[100];
    createDir("build");
    sprintf(comand_compile, "javac -d temp -cp . *.java %s.java", classFile);
    system(comand_compile);
}

void createDir(char *fileName) {
    if (access(fileName, F_OK) == 0) {
        int result;
        #ifdef _WIN32
        result = mkdir(fileName);
        #else
        result = mkdir(fileName, 0777);
        #endif
    }
}