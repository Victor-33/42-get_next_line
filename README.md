# 42 Cursus - Project: Get Next Line
<img src="https://game.42sp.org.br/static/assets/achievements/get_next_linem.png" alt="get_next_line">
The objective of this project is to create a function that returns a line that ends with a newline, read from a file descriptor. It will return one line at a time from a text file.

### Instructions to use

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

**To use it in your code is very simple**

Include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the required flags:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

if you use Linux, you should probably use the flags:

```shell
-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
```

This project introduces an interesting way of reading files in C. :)
