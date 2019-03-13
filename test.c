#include <stdio.h>

int rotateRight(int x, int n) {
  int mask = 1 << 31;
  int mask2;
  int val = 32 + (~n + 1);
  mask = ~mask;
  printf("%x\n", val);
  mask = mask + (1 << 31);
  printf("%x\n", mask);
  mask2 = mask << val;
  printf("Mask2: %x\n", mask2);
  mask2 = ~mask2;
  printf("Mask2: %x\n", mask2);
  mask <<= n;
  printf("%x\n", mask);
  mask = ~mask;
  printf("%x\n", mask);
  mask = mask & x;
  printf("%x\n", mask);
  mask <<= val;
  printf("%x\n", mask);
  x >>= n;
  printf("%x\n", x);
  printf("%x\n", mask2);
  x = x & mask2;
  printf("%x\n", mask);
  x = x | mask;
  printf("%x\n", x);
  return x;
}

int byteSwap(int x, int n, int m) {
  n = n << 3;
  m = m << 3;
  int mask = 0xFF;
  int mask2;
  int val = 33 + ~n;
  printf("%x\n", val);
  int val2 = 33 + ~m;
  printf("%x\n", val2);
  int byteN = (mask << n);
  printf("%x\n", byteN);
  int byteM = (mask << m);
  printf("%x\n", byteM);
  int juntos = byteM | byteN;
  juntos = ~juntos;
  printf("%x\n", juntos);
  byteN = byteN & x;
  printf("%x\n", byteN);
  byteM = byteM & x;
  printf("%x\n", byteM);
  x = x & juntos;
  printf("%x\n", x);
  byteN >>= n;
  printf("%x\n", byteN);
  mask2 = ~0 << val;
  printf("%x\n", mask2);
  mask2 = ~mask2;
  byteN &= mask2;
  printf("%x\n", byteN);
  byteM >>= m;
  mask2 = ~0 << val2;
  mask2 = ~mask2;
  byteM &= mask2;
  printf("%x\n", byteM);
  byteN <<= m;
  printf("%x\n", byteN);
  byteM <<= n;
  printf("%x\n", byteM);
  x = x | byteN | byteM;
  printf("%x\n", x);
  return x;
}

int isLess(int x, int y) {
  int menosx = ~x;
  int sub = y + menosx + 1;
  int equal = !(x ^ y);
  int equalmenos = !(y ^ menosx);
  int signaly = (y >> 31) & 1;
  printf("Signal Y: %x\n",signaly);
  int signalx = (x >> 31) & 1;
  printf("Signal X: %x\n",signalx);
  int doubleneg, doublepos, swapPos, swapNeg, zeroY;
  sub >>= 31;
  sub &= 1;
  printf("Signal Sub: %x\n",sub);
  doubleneg = (!sub & signalx & signaly);
  printf("%d\n",doubleneg);
  doublepos = (!sub & !signalx & !signaly);
  printf("%d\n",doublepos);
  swapPos = (!signaly & signalx);
  printf("%d\n",swapPos);
  swapNeg = !(signaly & !signalx);
  printf("%d\n",swapNeg);
  zeroY = (!y & signalx);
  printf("%d\n",zeroY);
  printf("%d\n",!equal);
  return ((doubleneg | doublepos | swapPos) & !!y & !equal) | zeroY;
}

int main() {
  printf("%d\n",isLess(0x80000000,0x80000000));
  return 1;
}