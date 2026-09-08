#include "utils.h"

int parse_int(char * str_int){
    if (!str_int) return 0;
    int n = strlen(str_int);
    int value = 0;
    for(int i=0; i<n; i++){
        if (*(str_int+i) > '9' || *(str_int+i) < '0') continue;
        value += (*(str_int+n-i-1)-'0')*(int)pow(10, i);
    }
    return value;
}

double parse(char * str_float){
    double value = 0;
    char * tok = strtok(str_float, ".");
    value += parse_int(tok);
    tok = tok+strlen(tok)+1;
    value += pow(0.1, strlen(tok))*parse_int(tok);
    return *str_float == '-'? -value : value;
}

