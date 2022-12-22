# Get_next_line_42_1337

A function that reads a single line from a file descriptor in C.
# Table of Contents

- ### [Overview](#overview)
- ### [Usage](#overview)
- ### [API](#overview)
- ### [Compiling](#compiling)

# Overview

get_next_line is a function that reads a single line from a file descriptor, returning the line read as a char *. It works with multiple file descriptors, allowing you to read from multiple files simultaneously.

This repository contains the source code for get_next_line, as well as a test suite and example programs that demonstrate its usage.
# Usage

To use the get_next_line function, you need to include the header file in your C program and open the file that you want to read using the open function. Then, allocate memory for a char * to store the line read by get_next_line and call the function with the file descriptor and the address of the char *. Check the return value of get_next_line to determine the status: if it is 1, a line was read successfully; if it is 0, the end of the file was reached; if it is -1, an error occurred. When you are finished with the char *, free the memory allocated for it.
```c++
int fd;
char *line;

line = get_next_line(fd);
```
The `get_next_line` function returns an integer indicating the status:

    * 1: A line was read successfully.
    * 0: End of file was reached.
    * -1: An error occurred.

# API

The get_next_line function has the following prototype:

```c++
int get_next_line(int fd, char **line);
```
# compiling
```bash
gcc -o program program.c -Wextra -Wall -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=10
```
or
```bash
gcc -o program program.c -Wextra -Wall -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=10 
```
