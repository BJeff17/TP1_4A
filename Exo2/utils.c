#include<string.h>
#include<stdio.h>

float power(float x, int n){
    float r = 1;
    for (int i=0;i<n;i++) r*=x;
    return r;
}

int power_int(int x, int n){
    return (int)power((float)x, n);
}

int parse_int(char * str_int){
    if (!str_int) return 0;
    int n = strlen(str_int);
    int value = 0;
    for(int i=0; i<n; i++){
        if (*(str_int+i) > '9' || *(str_int+i) < '0') continue;
        value += (*(str_int+n-i-1)-'0')*power_int(10, i);
    }
    return value;    
}

float parse_float(char * str_float){
    float value = 0;
    char * tok = strtok(str_float, ".");
    value += parse_int(tok);
    tok = tok+strlen(tok)+1;
    value += power(0.1, strlen(tok))*parse_int(tok);
    return *str_float == '-'? -value : value;
}


int main(){
    char v[]="210.1126638751";

    float t = parse_float(v);
    printf("%f", t);
    return 0;
}