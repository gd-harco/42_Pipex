

# <p align="center">42-Pipex</p>

<p align="center">Final grade :<br>
<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cle01db6o00650fmmx6igm6z3/project/2977163" alt="gd-harco's 42 pipex Score" /></a></p>

## 📑 Introduction
Pipex is a project that aims to recreate the behavior of a pipe in Shell. It uses 'dup' and 'dup2' to redirect different file descriptors, 'fork' to create child processes, and 'pipe' to handle communication between processes.

## 🖥️ Detailed Description
The Pipex project involves creating a program that reproduces the functionality of pipes in Shell. The program takes as input a source file, two shell commands (command1 and command2), and a destination file. The goal is to take the output of the first shell command (command1) and redirect it to the input of the second shell command (command2), and then redirect the output of the second shell command to the destination file.

To accomplish this, the program uses the 'pipe' function to create a communication channel between the two shell commands and the 'dup' function to duplicate file descriptors, which are used to redirect input and output.

##  ⚠️ Warning
This project is a part of the 42-Cursus curriculum and is intended for educational purposes. If you are a current student of 42, we strongly advise you not to copy this project or submit it as your own work, as it goes against the school's academic integrity policy. We will not be responsible for any misuse of the project or academic penalties that may arise from it. However, you are welcome to use this project as a reference or for learning purposes.

## 💽 Usage
```shell
./pipex "input file" "command 1" "command 2" "output file"
```


## 🙇 Author
#### Guillaume d'harcourt
- Github: [@gd-harco](https://github.com/gd-harco)<br>
<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cle01db6o00650fmmx6igm6z3/stats?cursusId=21&coalitionId=15" alt="gd-harco's 42 stats" /></a>
