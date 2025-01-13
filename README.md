# get_next_line

## Overview
The **get_next_line** project is about creating a function that reads a line from a file descriptor, returning it one line at a time. The main challenge is handling multiple file descriptors and efficiently managing memory while ensuring that the function works correctly for large files or edge cases.

---

## Features
- Reads one line at a time from a file descriptor.
- Handles multiple file descriptors simultaneously.
- Manages memory efficiently using buffers.
- Works with any file descriptor, including standard input (`0`), files, and pipes.

---

## Installation
1. Clone the repository:
   ```bash
   git clone git@github.com:d2iv3r/get_next_line.git
   cd get_next_line

## Usage

Once you've built your `libft.a` library, you can use it in your C projects by linking it during compilation. Here's how:

### 1. **Building the Library**
To build the library, run:
```bash
make
```

### 2. **Include get_next_line.h**

Add the following line to your .c file to use the get_next_line function:

```bash
#include "get_next_line.h"
```

### 3. **Compile Your Code with get_next_line.a**

Use the -L and -l flags to link the static library:


```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lget_next_line -o your_program
```
### Buffer Size

The BUFFER_SIZE macro determines how many bytes are read at a time from the file descriptor. It is defined during compilation or in the header file.

Setting BUFFER_SIZE
You can set the BUFFER_SIZE when compiling:

```bash
gcc -D BUFFER_SIZE=42 your_file.c -L. -lget_next_line -o your_program

```

### Prototype

```bash
char *get_next_line(int fd);
```