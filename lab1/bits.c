/* 
 * CS:APP Data Lab 
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

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team = 
{
    /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "516051910027",
    /* Student name 1: Replace with the full name of first team member */
    "YUAN Qichao",
    /* Login ID 1: Replace with the login ID of first team member */
    "516051910027",

    /* The following should only be changed if there are two team members */
    /* Student name 2: Full name of the second team member */
    "",
    /* Login ID 2: Login ID of the second team member */
    ""};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
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
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
   see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // 等价于寻找x转化为二进制后，有没有 1
  x |= x >> 16;   // 用后16位包括了整个数字有没有1的信息
  x |= x >> 8;    // 同上，折叠到8位
  x |= x >> 4;    // ...
  x |= x >> 2;
  x |= x >> 1;    // 最后折叠到最后一位
  return ~x & 1;  // 返回的只能为1或0，所以&1；表示的是！，所以用~
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int m1 = 0x11 | (0x11 << 8);
  int mask = m1 | (m1 << 16);
  int s = x & mask;
  s += x>>1 & mask;
  s += x>>2 & mask;
  s += x>>3 & mask;
  /* Now combine high and low order sums */
  s = s + (s >> 16);
  /* Low order 16 bits now consists of 4 sums.
  Split into two groups and sum */
  mask = 0xF | (0xF << 8);   // check  | -> ||
  s = (s & mask) + ((s >> 4) & mask);
  return (s + (s>>8)) & 0x3F;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  int mask = 0x1;           // mask code 0x1
  int m1 = x & mask;        // 保留了最后一位
  int m2 = (m1<<31)>>31;    // 将最后一位复制到全部32位
  return m2;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int signMask = x >> 31;
    return (x + (signMask & ((1 << n) + ~0))) >> n;
    //分类讨论，如果x >= 0, 那么 x/(2^n) = x >> n；如果 x < 0, 那么x/(2^n) = (x + (1 << n) - 1) >> n; 现在构造一个数 bias 使得在 x >= 0时，bias = 0；在 x < 0 时，bias = (1 << n) - 1; signMask = x >> 31, 表示如果x负数则，signMask = 0xFFFFFFFF；否则signMask = 0x0。所以 bias = signMask & (1 << n) + ～0) 。其中～0 = -1。
  //blog.csdn.net/qq_19762007/article/details/80038755?utm_source=copy 

}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
  int m = 0x55;
  return (m << 24)|(m << 16)|(m << 8)|m;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {  // 也就是说，最后检测的是 move 32-n位后，会不会改变x的值
  int m1 = 32 + (~n + 1);   // equal m1 = 32-n
  int m2 = (x << m1) >> m1; // m2 equals sign-filling x 
  return !(x^m2);          // if so, x == sign-filling x
}   // Reference:https://stackoverflow.com/questions/42790409/bitwise-operation-fitsbits
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int m = x >> (n << 3);
  return m & 0xFF;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  int z = x + (~y);     // z = x-y-1
  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int m1 = !!(sign_y & (!sign_x));   // x>0 && y<0 -> x>y
  int m2 = (!(z >> 31)) & (!(sign_x ^ sign_y));  // x>y>0 or 0>x>y
  return m1 | m2;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  int m = x >> 31;
  return !m;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  int z = x + (~y) + 1;
  return !!z;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 60
 *   Rating: 4
 */
int isPower2(int x){
  // 只能出现1个1
  int m1 = x >> 31;   // 首位不能是1
  int m2 = !!x;       //  x不能是0
  int m3 = x & (x + (~0));  // 只能出现1个1
  return !m1 & m2 & !m3;
}

/*{ // 有1必然是z1（从最高位开始的），1的左边一定是1,0的右边一定是0,而且首位不能是1(0x01除外)
  int sign_x = (x >> 31) & 0x1;   // 首位不能是1
  int ifx_1 = x ^ (0x01);         // 0x01除外
  x &= x >> 16;
  x &= x >> 8;
  x &= x >> 4;
  x &= x >> 2;
  x &= x >> 1;
  return ((!!x & !sign_x) | (!!ifx_1));
}*/
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
  return x & (~x+1);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int mask = 0x01 << 31;
  int m1 = x >> n;
  int m2 = ((~mask >> n) << 1 ) + 1;
  return m1 & m2;
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
/*  int sign_x = x >> 31;
  int sign_y = y >> 31;
  int sign_sum = (x + y) >> 31;
  int m1 = sign_x ^ sign_y; //   xy符号相同 -> m1 = 0
  // x,y异号，则!m1=0,直接返回x+y   !m1|(x+y)
  int m2 = sign_x ^ sign_sum;
  int m3 = sign_y ^ sign_sum;
  // x,y同号（m1=0) 当!m2或!m3有一个为0，溢出，返回sign_x
  // !m2&!m3=1，直接返回x+y
*/
	int ans = x + y;
	int overFlow = (( x ^ ans) & (y ^ ans)) >> 31;      // of -> 0x111....    not of -> 0
	return ( ans >> ( overFlow & 31 ) ) + ( overFlow << 31 ) ;
}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int tc2sm(int x) {
  int y = x >> 31 ;
  int m1 = y & 1;
  int m2 = (x + y) ^y;
  return (m1 << 31) | m2;
}
