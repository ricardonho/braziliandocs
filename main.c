#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "digits.h"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        printf("arguments error\n");
        return 0;
    }
    
    long result = 0;
    
    if(strcmp(argv[1], "cpf") == 0) {
        result = calculateDigitCPF(atoi(argv[2]));
    } else if(strcmp(argv[1], "cnpj") == 0) {
        char* aux;
        printf("%s %lu\n", argv[2], strtol(argv[2], &aux, 10));
        result = calculateDigitCNPJ(strtol(argv[2], &aux, 10));
    }
    
    if (argc > 3 && strstr(argv[3], "masked") != NULL) {
        char buffer[32];
        longToMaskString(result, buffer, argv[4]);
        printf("%s\n", buffer);
    } else {
        printf("%lu\n", result);
    }
    
    return 0;
    
    /*printf("%lu\n", calculateDigitCNPJ(595412640001));
    printf("%lu\n", calculateDigitCNPJ(60232660001));
    printf("%lu\n", calculateDigitCPF(295037808));
    printf("%lu\n", calculateDigitCPF(307766058));
    printf("%lu\n", calculateDigitCPF(875173968));
    
    //generateAll("cpf.txt", calculateDigitCNPJ, 1000000000, "###.###.###-##");
    generateAll("cnpj.txt", calculateDigitCNPJ, 0, 100000000, "##.###.###/####-##");
    */
    //1000000000
    //100000000
    /*char* buffer = malloc(16);
    printf("%s\n", longToMaskString(6023266000136, buffer, "##.###.###/####-##"));
    free(buffer);
    */
   return 0;
}
