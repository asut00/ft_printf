# ft_printf 🖨️

This project is a custom implementation of the C library function `printf`, built from scratch. It replicates much of the functionality of the original `printf` function while offering a deeper understanding of variadic functions and formatted output.

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Conversions](#supported-conversions)
- [Testing](#testing)
- [Author](#author)

## About the Project

The **ft_printf** project, part of the [42 School](https://42.fr/) curriculum, focuses on reimplementing the `printf` function in C. The goal is to replicate its core features, handle various data types, and gain experience working with variadic functions, which allow for functions to accept a variable number of arguments.

## Features

**ft_printf** replicates the main functionality of `printf`, with support for:
- Character and string printing
- Integer and unsigned integer printing (including hexadecimal)
- Pointer address printing
- Percentage sign printing

This project was completed without using standard library functions like `printf`, `sprintf`, or `snprintf`, ensuring a fully custom approach.

## Installation

To compile and integrate **ft_printf** into your project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/asut00/ft_printf.git
   cd ft_printf
   ```

2. Compile the library:
   ```bash
   make
   ```

3. You’ll get a `libftprintf.a` file that you can link with any C project:
   ```bash
   gcc yourfile.c -L. -lftprintf -o yourprogram
   ```

## Usage

To use **ft_printf** in your project, include the `ft_printf.h` header:
```c
#include "ft_printf.h"
```

You can now call `ft_printf` as you would with the standard `printf` function. For example:
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s! Your score is %d.\n", "user", 42);
    return 0;
}
```

## Supported Conversions

The **ft_printf** project supports the following conversion specifiers:

| Specifier | Description                |
|-----------|----------------------------|
| `%c`      | Print a single character   |
| `%s`      | Print a string of characters |
| `%p`      | Print a pointer address    |
| `%d`/`%i` | Print an integer           |
| `%u`      | Print an unsigned integer  |
| `%x`/`%X` | Print a hexadecimal (lower/upper case) |
| `%%`      | Print a percentage sign    |

## Author

- GitHub: [@asut00](https://github.com/asut00)  
- 42 Intra: `asuteau`
