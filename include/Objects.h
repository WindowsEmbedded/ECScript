#ifndef ES_OBJECT_H_
#define ES_OBJECT_H_
#include <langException.h>
char Numbers[11] = "0123456789";

bool isNumber(char Char) { 
    //bool numflag = false;
    for(int i=0;i<=9;i++) {
        if(Char == Numbers[i]) return true;
    }
    return false;
}
#endif