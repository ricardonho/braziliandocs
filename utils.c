#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longToMaskString(unsigned long value, char* buffer, const char* mask) {
    
    unsigned int size = strlen(mask);
    
    for(int i = size; i > -1; --i) {
        if (mask[i] == '#') {
            buffer[i] = '0' + (value % 10);
            value /= 10;
        } else {
            buffer[i] = mask[i];
        }
    }
    
    return buffer;
}