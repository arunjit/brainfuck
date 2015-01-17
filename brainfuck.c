#include <stdio.h>

int main() {
  char array[256] = {0};
  char *ptr = array;
  char input;
  int skip;
  char *code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---."
               "+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  int i, loopIndex;
  int loops[16];
  for (i = 0; i < 16; i++) loops[i] = -1;

  skip = 0;
  loopIndex = -1;

  for (i = 0; (code[i]); i++) {
    if (skip) continue;
    input = code[i];
    switch(input) {
      case '>': ++ptr; break;  // TODO: overflow
      case '<': --ptr; break;  // TODO: underflow
      case '+': ++*ptr; break;
      case '-': --*ptr; break;
      case '.': putchar(*ptr); break;
      case ',': *ptr = getchar(); break;
      case '[':
        if (*ptr) {
          if (loops[loopIndex] != i) loops[++loopIndex] = i;
        } else skip = 1;
        break;
      case ']':
        skip = 0;
        if (*ptr) i = loops[loopIndex] - 1;
        else loops[loopIndex--] = -1;
        break;
      default: break;
    }
  }

}
