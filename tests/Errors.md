# PRINT_F TESTS

## Problem 1
### How to avoid printing format specifiers `%` and `c || s || d || i ...` 

> To solve this problem, I increased the index by 1 once a switch statement was 
> satisfied. Easy, Right? 

## Problem 2
### String is not printed wholly when it appears in the middle of `format`.

> In `_printf` i.e., `_printf("%c Hello %s Wolrd %c", 'x', "Panda", 'b')`
> The string `Panda` will not be printed wholly. Only 2 bytes of `Panda` will be printed

#### Solution to Problem 2 
> This problem was solved by changing the index buffer from `i` to `j` and increasing 
> index `i` after a case is satisfied i.e., before the `switch-case` check. 
