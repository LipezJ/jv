#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef _WIN32
#define SEPARATOR "\\"
#define COMPILE_CMD "javac -d %s -cp .%ssrc src%s*.java src%s%s.java"
#else
#define SEPARATOR "/"
#define COMPILE_CMD "javac -d %s -cp . src%s**%s*.java src%s%s.java"
#endif

#define BUILDDIR "build"
#define BINDIR "bin"

#define EXECUTE_CMD "java -cp %s %s"
#define JAR_CMD "jar cvfm %s%s%s.jar manifest.mf -C %s ."
#define JAR_EXECUTE_CMD "java -jar %s%s%s.jar"

void usage();
void compile(char *classFile);
void compileJava(char* jarName, char* className);
void execute(char* fileName);
void executeJava(char* jarName);
int createProject(char *projectName);
void createDir(char *dirName);
void createFile(char *command,char *content);

int main(int argc, char** argv) {
    if (strcmp(argv[1], "--new") == 0 && argc == 3)
        createProject(argv[2]);
    else if (strcmp(argv[1], "-j") == 0 && argc == 4) 
        compileJava(argv[3], argv[2]);
    else if (strcmp(argv[1], "-c") == 0 && argc == 3) {
        compile(argv[2]);
        printf("\nCompile completed");
    } else if (strcmp(argv[1], "--run") == 0 && argc == 3)
        executeJava(argv[2]);
    else if (argc == 2) 
        execute(argv[1]);
    else {
        printf("\nError: No arguments provided.\n");
        usage();
    }
    return 0;
}

void execute(char* fileName) {
    char command[100];
    createDir(BUILDDIR);
    compile(fileName);
    sprintf(command, EXECUTE_CMD, BUILDDIR, fileName);
    if (system(command) == -1)
        printf("\nSuggestion: Make sure you enter valid file names\n");
    printf("\nExecute completed");
}

void compileJava(char* jarName, char* className) {
    char command_jar[100];
    createDir(BUILDDIR);
    compile(className);
    sprintf(command_jar, JAR_CMD, BINDIR, SEPARATOR, jarName, BUILDDIR);
    if (system(command_jar) == -1) 
        printf("\nSuggestion: Make sure you enter valid file names and that the manifest.mf file exists in the root directory\n");
    printf("\nCompile Jar completed");
}

void  compile(char *classFile) {
    char command_compile[100];
    createDir(BUILDDIR);
    sprintf(command_compile, COMPILE_CMD, BUILDDIR, SEPARATOR, SEPARATOR, SEPARATOR, classFile);
    if (system(command_compile) == -1) 
        printf("\nSuggestion: Make sure you enter valid file names\n");
}

void executeJava(char* jarName) {
    char command_jar[100];
    sprintf(command_jar, JAR_EXECUTE_CMD, BINDIR, SEPARATOR, jarName);
    if (system(command_jar) == -1) 
        printf("\nSuggestion: Make sure you enter valid file names\n");
    printf("\nExecuted Jar completed");
}

void createDir(char *dirName) {
    if (access(dirName, F_OK) != 0) {
        #ifdef _WIN32
            _mkdir(dirName);
        #else
            mkdir(dirName, 0777);
        #endif
    }
}

void createFile(char *command,char *content) {
    FILE *file = fopen(command, "w");
    if (file == NULL) {
        printf("Error creating files\n");
        exit(-1);
    }
    fprintf(file, content);
    fclose(file);
}

int createProject(char *projectName) {
    char command[100];

    createDir(projectName);
    sprintf(command, "%s%ssrc", projectName, SEPARATOR);
    createDir(command);
    sprintf(command, "%s%s%s", projectName, SEPARATOR, BUILDDIR);
    createDir(command);
    sprintf(command, "%s%s%s", projectName, SEPARATOR, BINDIR);
    createDir(command);

    sprintf(command, "%s%ssrc%sMain.java", projectName, SEPARATOR, SEPARATOR);
    createFile(command, "public class Main {\n\tpublic static void main(String[] args) {\n\t\tSystem.out.println(\"Hello\");\n\t}\n}");
    sprintf(command, "%s%smanifest.mf", projectName, SEPARATOR);
    createFile(command, "Main-Class: Main\nClass-Path: .");

    printf("\n%s created successfully.\n", projectName);
    return 0;
}

void usage() {
    printf("\nUsage:\n\tjv [-c -j] <Class name> <Jar name>\n\n");
    printf("-j -> compile the code in the build folder and generate the .jar executable\n");
    printf("-c -> compile the code in the build folder\n\n");
    printf("jv [--new --run] <project's name or .jar name>\n\n");
    printf("\t--new -> generate a new java project");
    printf("\t--run -> runs the specified .jar file");
}