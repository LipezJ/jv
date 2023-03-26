## jv - Compile and run java with a single line ☕

jv is a command line tool written in C that allows you to compile, run code, and build simple Java projects quickly and easily. With JV, you will be able to:

- Build simple Java projects with a basic file structure for a project.
- Compile Java code and generate .class files.
- Generate executable .jar files from compiled Java code.
- Run Java code and .jar files.

### Requirements
- Java Development Kit (JDK) 1.8 or later installed.
- **javac** and java **commands** added to the system PATH.

### Use:
jv provides several commands for automating Java project setup, compilation, and execution. Here is a list of available commands:

- ``` jv --new <project_name>``` Creates a new Java project with the specified name. This command will generate a basic file and folder structure for your project, including a Main.java file with a basic main function.
   
  - The project created with this command will have the following structure:
    ```
      <project's name>/
      ├── build/
      ├── bin/
      └── src/
          └── Main.java
    ```
- ```jv <class_name>``` Compiles and runs the specified class. 
- ```jv -c <class_name>``` Compiles the specified Java file and generates a .class file in the build folder. 
- ```jv -j <jar_name> <class_name>``` Compiles the specified Java file and generates an executable .jar file in the bin folder.
- ```jv --run <file_name>``` Runs the specified Java file or .jar file.

### Installation
To use jv, you must first compile the jv.c file and add the resulting executable to your system's path.

#### Compiling jv.c
To compile jv.c, you will need a C compiler such as gcc. Follow these steps to compile the file:

1. Open a terminal window.
2. Navigate to the directory where jv.c is located.
3. Run the following command to compile jv.c:  

```bash
gcc jv.c -o jv
```  
This will create an executable file named jv in the same directory.

#### Adding jv to the system's path
To use jv from anywhere on your system, you must add the directory where the jv executable is located to your system's path. Follow these steps to add jv to your path:

##### Windows
Open the Start menu and search for "Environment Variables".
 
1.  Click "Edit the system environment variables".
2.  Click the "Environment Variables" button.
3.  Under "System variables", scroll down and find the "Path" variable.
4.  Click "Edit".
5.  Click "New" and enter the full path to the directory where the jv executable is located.
6.  Click "OK" on all open windows to save your changes.
 
##### Linux / macOS

1. Open a terminal window.
2. Run the following command to open your shell's configuration file:  

   ```bash
   nano ~/.bash_profile
   ```  
   **_Note:_** If you use a different shell, replace ```~/.bash_profile``` with the configuration file for your shell (e.g., ~/.zshrc for zsh).
3. Add the following line to the file:  

   ```bash
   export PATH=$PATH:/path/to/directory
   ```  
   Replace ```/path/to/directory``` with the full path to the directory where the jv executable is located.
4. Press **Ctrl+X**, then **Y**, then **Enter** to save the file.
5. Run the following command to update your shell:  

   ```bash
   source ~/.bash_profile
   ```  
   **_Note:_** If you use a different shell, replace ```~/.bash_profile``` with the configuration file for your shell.

### Contributions
If you would like to contribute to this project, you can send a Pull Request or create an ISSUE. Any contribution is welcome.
