#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utils.h"
#include "digits.h"

unsigned long calculateDigitCPF(unsigned long cpf) {
//1	4	5	3	8	2	2	0	6
//X	X	X	X	X	X	X	X	X
//10	9	8	7	6	5	4	3	2
//10	36	40	21	48	10	8	0	12

  unsigned long c = cpf;
  unsigned long r1 = 0;
  unsigned long r2 = 0;
  unsigned int d = 100000000;
  unsigned int i = 0;
  unsigned int m = 10;

  for(i = 0;i < 9; ++i) {
    r1 += c / d * m;
    c = c % d;
    d = d / 10;
    --m;
  }

  r1 %= 11;
  r1 = (11 - r1 >= 10) ? 0 : 11 - r1;
 
  c = cpf * 10 + r1;
  d = 1000000000;
  i = 0;
  m = 11;

  for(i = 0; i < 10; ++i) {
    r2 += c / d * m;
    c = c % d;
    d = d / 10;
    --m;
  }

  r2 %= 11;
  r2 = (11 - r2 >= 10) ? 0 : 11 - r2;
  return cpf * 100 + r1 * 10 + r2;
}

unsigned long calculateDigitCNPJ(unsigned long cnpj) {
    
    // 2    3	4	5	6	7	8	9	2	3	4	5
    unsigned long aux = cnpj;
    unsigned int digits[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    unsigned int multiples[] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6};    
    unsigned int digit1 = 0, digit2 = 0;
    
    for(int i = 0; i < 12; ++i) {
        digits[i] = aux % 10;
        digit1 += digits[i] * multiples[i];
        aux /= 10;
    }
    
    digit1 %= 11;
    digit1 = (11 - digit1 < 10) ? 11 - digit1 : 0;  
    aux = cnpj = (cnpj * 10) + digit1;
    
    for(int i = 0; i < 13; ++i) {
        digits[i] = aux % 10;
        digit2 += digits[i] * multiples[i];
        aux /= 10;
    }
    
    digit2 %= 11;
    digit2 = (11 - digit2 < 10) ? 11 - digit2 : 0;      
    cnpj = (cnpj * 10) + digit2;
    
    return cnpj;
}

unsigned int documentsFlush(const char* filePath, 
                            calculateDigitFunction method, 
                            unsigned long init,
                            unsigned long depth, 
                            const char* mask) {

  if (init >= depth) return 0;
                     
  unsigned long i;
  unsigned long c;
  char buffer[32];
  
  FILE* f = fopen(filePath, "wb+");

  if(f != NULL) {

    for(i = init; i < depth; ++i) {
        
       c = method(i * 10000 + 1);
       
       if(mask != NULL) longToMaskString(c, buffer, mask);
       
       fwrite(buffer, strlen(buffer), 1, f);
       
       fwrite("\r\n",2,1,f);
       
       if(i % 10000000 == 0) printf("%lu\n", i);
    }

    fclose(f);
    
    return 1;
  }
  
  return 0;
}
