/*
 * hello.c
 *
 * Optimization in C Sandbox
 *
 * Siddharth Garimella
 */
#include <stdio.h>

/*

    Two versions of this file were compiled and run, one with
    the -O2 flag and one without it. Assembly code was produced
    for each and diffed to analyze how optimization works.

    Roughly speaking, the optimized version of hello.c had fewer
    assembly instructions than the unoptimized version (wc -l 
    counted 4 fewer lines in the optimized assembly code). 

    The important differences are as follows:

    Instead of reserving 32 bytes of space on the stack for x and y,
    the optimized version reserved only 16 bytes, just for y.

    -       subl    $32, %esp
    ---
    +       subl    $16, %esp

    In the unoptimized version, 5 was put into %esp, and output to %eax.
    Then, as per the code, 1 was added to %eax (5), and %eax was our result, 6.
    Finally, y's value, 6, was stored in %esp.

    The optimized version stored nothing but the result, 6 to y. Who needed x, anyway?

    -       movl    $5, 28(%esp)
    -       movl    28(%esp), %eax
    -       addl    $1, %eax
    -       movl    %eax, 24(%esp)
    -       movl    24(%esp), %eax
    -       movl    %eax, 4(%esp)
    ---
    +       movl    $6, 4(%esp)

    This is just changing the way %eax is reset to zero. I think the xor instruction
    is often faster than most other instructions, in this case it is better than mov.

    I wonder why it defaulted to mov. My guess is that it's the "return 0" line.

    -       movl    $0, %eax
    ---
    +       xorl    %eax, %eax


*/
int main() {
    int x = 5;
    int y = x + 1;
    printf("y: %d",y);
    return 0;
}

