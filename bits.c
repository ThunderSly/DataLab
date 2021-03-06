/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* bits */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

  int w = (~x) & (~y);
  int z = x & y;
  int b = (~w) & (~z);
  return b;
}
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  x = x & (x >> 16);
  x = x & (x >> 8);
  x = x & (x >> 4);
  x = x & (x >> 2);
  x &= 1;
  return x;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  int mask, byteN, byteM, juntos;
  n = n << 3;
  m = m << 3;
  mask = 0xFF;
  byteN = (mask << n);
  byteM = (mask << m);
  juntos = byteM | byteN;
  juntos = ~juntos;
  byteN = byteN & x;
  byteM = byteM & x;
  x = x & juntos;
  byteN >>= n;
  byteM >>= m;
  byteN &= mask;
  byteM &= mask;
  byteN <<= m;
  byteM <<= n;
  x = x | byteN | byteM;
  return x;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  int mask = 1 << 31;
  int mask2;
  int val = 32 + (~n + 1);
  mask = ~mask;
  mask = mask + (1 << 31);
  mask2 = mask << val;
  mask2 = ~mask2;
  mask = x << val;
  x >>= n;
  x &= mask2;
  x = x | mask;
  return x;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int sum = 0;
  sum += !!(1 & x);
  sum += !!((1 << 1) & x);
  sum += !!((1 << 2) & x);
  sum += !!((1 << 3) & x);
  sum += !!((1 << 4) & x);
  sum += !!((1 << 5) & x);
  sum += !!((1 << 6) & x);
  sum += !!((1 << 7) & x);
  sum += !!((1 << 8) & x);
  sum += !!((1 << 9) & x);
  sum += !!((1 << 10) & x);
  sum += !!((1 << 11) & x);
  sum += !!((1 << 12) & x);
  sum += !!((1 << 13) & x);
  sum += !!((1 << 14) & x);
  sum += !!((1 << 15) & x);
  sum += !!((1 << 16) & x);
  sum += !!((1 << 17) & x);
  sum += !!((1 << 18) & x);
  sum += !!((1 << 19) & x);
  sum += !!((1 << 20) & x);
  sum += !!((1 << 21) & x);
  sum += !!((1 << 22) & x);
  sum += !!((1 << 23) & x);
  sum += !!((1 << 24) & x);
  sum += !!((1 << 25) & x);
  sum += !!((1 << 26) & x);
  sum += !!((1 << 27) & x);
  sum += !!((1 << 28) & x);
  sum += !!((1 << 29) & x);
  sum += !!((1 << 30) & x);
  sum += !!((1 << 31) & x);
  return sum;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int minusone = ~0;
  int zeroCheck = ~(!x + minusone);
  int answer = ((zeroCheck & z) | (~zeroCheck & y));
  return answer;
}
/* complemento de 2 */
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int tmin = x + 1;
  int tmax = ~tmin;
  int checkZero = !tmin;
  return !(x ^ tmax) & !checkZero;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
  int sub = y + ~x + 1;
  int equal = !(x ^ y);
  int signaly = (y >> 31) & 1;
  int signalx = (x >> 31) & 1;
  sub = (sub >> 31) & 1;

  return (((!sub & signalx & signaly) | (!sub & !signalx & !signaly) | (!signaly & signalx)) & !equal) | (!y & signalx);
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  x >>= 31;
  return !x;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  int signalx = (x >> 31) & 1;
  int signaly = (y >> 31) & 1;
  int signaldiff = ((x + ~y + 1) >> 31) & 1;
  return !((signalx & !signaly & !signaldiff) | (!signalx & signaly & signaldiff));
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
  return 2;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  int z = !(x ^ y);
  return !z;
}
/* float */
/* 
 * float_nan - Return 1 if float is NaN, 0 otherwise
 *   Max ops: 10
 *   Rating: 1
 */
int float_nan(unsigned uf) {
  int onlyFrac = 0x7FFFFF & uf;
  int allExpo = 0xFF << 23;
  int onlyExpo = allExpo & uf;

  return ((onlyExpo == allExpo) && onlyFrac);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  int allExpo = 0xFF << 23;
  int onlyExpo = allExpo & uf;
  int onlySign = (1 << 31) & uf;

  if (onlyExpo == allExpo) {
    return uf;
  }

  if (uf == 0x80000000 || uf == 0) {
    return uf;
  }

  if (onlyExpo != 0) {
    uf += (1 << 23);
    return uf;
  }

  else {
    return (uf << 1) | onlySign;
  }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int signal = (1 << 31) & x;
  int count = 0;
  int tmax = ~(1 << 31);
  int frac;
  int expo;
  int copy;
  int answer;
  if (x == 0) {
    return 0;
  }

  if (signal != 0) {
    x = ~x + 1;
  }
  copy = x;
  while (!(x & (1 << 31))) {
    x <<= 1;
    count += 1;
  }
  frac = x & tmax;
  frac >>= 8;
  frac &= 0x7fffff;
  expo = 158 - count;
  expo <<= 23;
  if (((x & 0xFF) > 128 ) || ((frac&1) && ((x&0x80)))) {
    frac += 1;
  }
  answer = signal + expo + frac;
  return answer;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  unsigned int tmax = (1 << 31);
  unsigned int abs = uf & ~tmax;

  int onlyFrac = 0x7FFFFF & uf;
  int allExpo = 0xFF << 23;
  int onlyExpo = allExpo & uf;

  if ((onlyExpo == allExpo) && onlyFrac) {
    return uf;
  }
  return abs;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int onlyFrac = 0x7FFFFF & uf;
  int allExpo = 0xFF << 23;
  int onlyExpo = allExpo & uf;

  if ((onlyExpo == allExpo) && onlyFrac) {
    return uf;
  }
  uf = uf ^ (1 << 31);
  return uf;
}
