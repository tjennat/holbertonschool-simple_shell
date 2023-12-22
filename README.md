
# C - Simple Shell





## Objective

Write a simple UNIX command interpreter.
## Description


This project implements a simple command-line interpreter (shell) in the C programming language. The shell allows the user to enter commands in the command line, interprets them, and then executes them by creating processes. It also supports some basic features such as environment management, execution of built-in commands, and error handling. This shell is designed as part of a system programming training project and aims to provide a basic understanding of how a Unix shell works.
## Mandatory tasks

- Task 0. README, man, AUTHORS  
- Task 1. Betty would be proud  
- Task 2. Simple shell 0.1  
- Task 3. Simple shell 0.2  
- Task 4. Simple shell 0.3  
- Task 5. Simple shell 0.4  
- Task 6. Simple shell 1.0
## Requirements

- Allowed editors: vi, vim, emacs.
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options ```-Wall -Werror -Wextra -pedantic -std=gnu89```.
- All your files should end with a new line.
- A README.md file, at the root of the folder of the project is mandatory.
- Your code should use the Betty style. It will be checked using betty-style.pl and - betty-doc.pl.
- Your shell should not have any memory leaks.
- No more than 5 functions per file.
- All your header files should be include guarded.
- Use system calls only when you need to.
## Compilation

This code sould be compiled using this commande: ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```


## Prototypes

- ```char *find_path(char *command);```
Finds the full path of a given command in the system's PATH directories. Returns the path or NULL if not found.
 
- ```void exec(char **args);```
Executes a specified command with arguments in a Unix shell, handling command not found errors and displaying messages.  

- ```void tokenize(char *line, char *args[], size_t max_args);```
Tokenizes a string into an array for command and argument parsing in the Unix shell.

- ```int main(void);```
Main entry point for the Unix shell program. Reads user commands, tokenizes, and executes functions. Typing "exit" terminates the shell.


## File Descriptions

| File Name                | Description                      |
|--------------------------|----------------------------------|
| AUTHORS                  | Authors of the project           |
| exec.c                   | Implementation of exec function  |
| getpath.c                | Implementation of find_path function |
| main.h                   | Header file containing function prototypes |
| man_1_simple_shell       | Manual page for the shell        |
| shell.c                  | Main implementation of the shell |
| token.c                  | Implementation of tokenize function |

## Exemples

Voici quelques exemples de commandes simples que le shell peut exécuter :

1. **Afficher le répertoire courant :**
    ```sh
    pwd
    ```

2. **Lister les fichiers dans le répertoire courant :**
    ```sh
    ls
    ```

3. **Créer un répertoire :**
    ```sh
    mkdir my_directory
    ```

4. **Changer de répertoire :**
    ```sh
    cd my_directory
    ```

5. **Afficher le contenu d'un fichier :**
    ```sh
    cat filename.txt
    ```

6. **Compiler un programme C :**
    ```sh
    gcc my_program.c -o my_program
    ```

7. **Exécuter un programme compilé :**
    ```sh
    ./my_program
    ```

8. **Supprimer un fichier :**
    ```sh
    rm file_to_delete.txt
    ```

9. **Afficher l'aide du shell (si vous avez implémenté une commande d'aide) :**
    ```sh
    help
    ```

10. **Quitter le shell :**
    ```sh
    exit
    ```

Ces exemples illustrent quelques fonctionnalités de base de votre shell, y compris la navigation dans les répertoires, la manipulation de fichiers, la compilation et l'exécution de programmes, ainsi que l'utilisation de commandes système courantes.

## Authors

- [@Théo Jennat](https://github.com/tjennat)
- [@Adonis Riahi](https://github.com/Adolberton)
