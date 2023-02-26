#ifndef ES_EXCEPTION_H_
#define ES_EXCEPTION_H_
#include <string.h>
#include <iostream>
class Exceptions {
    public:
        char errornames[2147];
        Exceptions(char errorname[]) {
            strcpy(errornames,errorname);
        }
};
class TypeError:public Exceptions {
    public:
        TypeError():Exceptions("TypeError") {}
};
class Interrupt:public Exceptions {
    public:
        Interrupt():Exceptions("Interrupt") {}
};
void raiseError(Exceptions err,char msg[]) {
    std::cout << "\nError (name:"<< err.errornames << "):" << msg << "\n";
    return;
}
#endif