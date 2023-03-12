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
void execute(char** argv);
int createProject(char *projectName);

int main(int argc, char** argv) {
    if (strcmp(argv[1], "--new") == 0 && argc == 3)
        createProject(argv[2]);
    else if (strcmp(argv[1], "-j") == 0 && argc == 4) 
        compileJava(argv);
    else if (strcmp(argv[1], "-c") == 0 && argc == 3) 
        compile(argv[2]);
    else if (argc == 2) 
        execute(argv);
    else {
        printf("use:\n\tjv [-c -j] <Class name> <Jar name>\n\n");
        printf("-j -> compile the code in the temp folder and generate the .jar executable\n");
        printf("-c -> compile the code in the temp folder\n\n");
        printf("jv [--new] <project's name>\n\n");
        printf("\t--new -> generate a new java project");
    }
    return 0;
}

void execute(char** argv) {
    char command[100];
    createDir("temp");
    compile(argv[1]);
    sprintf(command, "java -cp build %s", argv[1]);
    system(command);
}

void compileJava(char** argv) {
    char comand_jar[100];
    createDir("temp");
    compile(argv[2]);
    sprintf(comand_jar, "jar cvfm bin%s%s.jar manifest.mf -C build .", SEPARATOR, argv[3], SEPARATOR);
    system(comand_jar);
}

void compile(char *classFile) {
    char comand_compile[100];
    createDir("build");
    sprintf(comand_compile, "javac -d build -cp . src%s*.java src%s%s.java", SEPARATOR, SEPARATOR, classFile);
    system(comand_compile);
}

void createDir(char *fileName) {
    if (access(fileName, F_OK) == 0) {
        #ifdef _WIN32
        mkdir(fileName);
        #else
        mkdir(fileName, 0777);
        #endif
    }
}

int createProject(char *projectName) {
    char command[100];

    #ifdef _WIN32
        mkdir(projectName);
        sprintf(command, "%s\\src", projectName);
        mkdir(command);
        sprintf(command, "%s\\build", projectName);
        mkdir(command);
        sprintf(command, "%s\\bin", projectName);
        mkdir(command);
        sprintf(command, "%s\\src\\Main.java", projectName);
    #else
        mkdir(projectName, 0777);
        sprintf(command, "%s/src", projectName);
        mkdir(command, 0777);
        sprintf(command, "%s/build", projectName);
        mkdir(command, 0777);
        sprintf(command, "%s/bin", projectName);
        mkdir(command, 0777);
        sprintf(command, "%s/src/Main.java", projectName);
    #endif

    FILE *file = fopen(command, "w");
    if (file == NULL) {
        printf("Error creating Main.java\n");
        return -1;
    }
    fclose(file);

    printf("%s created successfully.\n", projectName);
    return 0;
}