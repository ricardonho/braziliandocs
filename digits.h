#ifndef __DIGITS_H__
#define __DIGITS_H__

typedef unsigned long (*calculateDigitFunction)(unsigned long);

unsigned long calculateDigitCPF(unsigned long);

unsigned long calculateDigitCNPJ(unsigned long);

unsigned int documentsFlush(const char*, 
                            calculateDigitFunction, 
                            unsigned long,
                            unsigned long, 
                            const char*);

#endif //__DIGITS_H__
