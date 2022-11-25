#include <stdio.h> 
#include <stdint.h>

//return a+b
int64_t asm_add(int64_t a, int64_t b){
  __asm__("addq %%rbx, %%rax" 
          :"=a" (b)
          : "a" (a), "b"(b)
          );
  return b;
}

//return a-b
int64_t asm_sub(int64_t a, int64_t b){
  __asm__("subq %%rbx,%%rax" 
          :"=a" (a)
          : "a" (a), "b " (b)
          );
  return a;
}


int main(){
  int64_t a = 10;
  int64_t b = 15;
  int64_t temp_add = asm_add (a,b);
  int64_t temp_sub = asm_sub(a,b);
  printf("temp_add=%ld, temp_sub=%ld\n", temp_add, temp_sub);
}
