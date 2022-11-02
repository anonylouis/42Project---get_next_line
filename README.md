# 42Project---get_next_line

Implementation of the get_next_line function : ```char *get_next_line(int fd)```

- The function take one parameter, a file descriptor (int)
- Read the file descriptor until an end of line is reach
- Return the line previusly read (in a char *)

[*en.subject.pdf*](https://github.com/anonylouis/42Project---get_next_line/blob/main/en.subject.pdf) is the original subject of the project from 42Paris !

To use the function just include the *get_next_line.h* in your file and add *get_next_line.c* and *get_next_line_utils.c* to your sources.

**Also don't forget to define BUFFER_SIZE before adding *get_next_line.h* with something like ```#define BUFFER_SIZE 42```**

---

The Makefile provide an exemple of utilisation of the function:

`make` compile the ./main.c

`make bonus` compile the ./main_bonus.c
