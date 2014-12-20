#include <stdio.h>

int main() {
  char array[0xFFFF] = {0};
  char *ptr = array;
  char input;
  int skip;
  // char *code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---."
  //              "+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  char *code = ">++++++++++++++++++++++++++++++++++++++++++++++++<++[>.<-]"
               ">+++++++.>>++++++++++."; // prints "007"
  int i, loopIndex;

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
        if (*ptr) loopIndex = i;
        else skip = 1;
        break;
      case ']':
        skip = 0;
        if (*ptr) i = loopIndex - 1;
        else loopIndex = -1;
        break;
      default: break;
    }
  }

}
