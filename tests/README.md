# PRINT_F TESTS

## Problem 1
### How to avoid printing format specifiers `%` and `c || s || d || i ...` 

> To solve this problem, I increased the index by 1 once a switch statement was 
> satisfied. Easy, Right? 

## Problem 2
### String is not printed wholly when it appears in the middle of `format`.

> In `_printf` i.e., `_printf("%c Hello %s Wolrd %c", 'x', "Panda", 'b')`
> The string `Panda` will not be printed wholly. Only 2 bytes of `Panda` will be printed
