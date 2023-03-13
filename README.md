## jv - Compile and run java with a single line ☕

JV is a command line tool written in C that allows you to compile, run code, and build simple Java projects quickly and easily. With JV, you will be able to:

- Build simple Java projects with a basic file structure for a project.
- Compile Java code and generate .class files.
- Generate executable .jar files from compiled Java code.
- Run Java code and .jar files.

### Requirements
- Java Development Kit (JDK) 1.8 or later installed.
- **javac** and java **commands** added to the system PATH.

### Use:
JV is used via the command line. These are the available commands:

- ``` jv --new <project_name>``` Creates a new Java project with the specified name. This command will generate a basic file and folder structure for your project, including a Main.java file with a basic main function.
   
  - The project created with this command will have the following structure:
    ```
      <project's name>/
      ├── build/
      ├── bin/
      └── src/
          └── Main.java
    ```
- ```jv -c <class_name>``` Compiles the specified Java file and generates a .class file in the build folder. 
- ```jv -j <jar_name> <class_name>``` Compiles the specified Java file and generates an executable .jar file in the bin folder.
- ```jv --run <file_name>``` Runs the specified Java file or .jar file.

### Contributions
If you would like to contribute to this project, you can send a Pull Request or create an ISSUE. Any contribution is welcome.
