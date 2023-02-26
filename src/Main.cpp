#ifdef __cplusplus
//extern "C"{
#endif
#include <iostream>
#include <string.h>
//#include <stdio.h>
//extern "C"{
#include <fstream>
//}

#include <map> //dict类型
#include <vector>
#include <langException.h>
#include <Objects.h>
#include <signal.h>
#define VER 0.15
enum Bool{True=1,False=0};
char Number[10] = {'0','1','2','3','4','5','6','7','8','9'};

int main(int argc,char *argv[]); 
int Shell();
void Run();
using namespace std;
//char Codes[214753][214753];

void sigintHandle(int sig) {
    Interrupt err;
    if (sig == SIGINT) {
        raiseError(err,"KeyboardInterrupt\n");
        exit(130);
    }
}

int Shell() {
    string cmds;
    bool numflag = false;
    int i=0;
    cout << "ECScript "<<VER<<"\n";
    while(1) {
        cout << ">>>";cin>>cmds;
        if (isNumber(cmds[0]) && cmds.length() == 1) {
            cout << cmds[0] << "\n";
        }
    }
    return 0;
}

void Run(string code,int line) {
    vector<string> codes;
    if(code[0] == '#' || code == "") {
        //cout << "commits" << endl;
    } else {
        char *tokenPtr = strtok((char*)code.c_str()," "); //分割字符串
        while(tokenPtr != NULL) {
            //cout << tokenPtr << endl;
            codes.push_back(tokenPtr);
            tokenPtr = strtok(NULL," ");
        } 
        if(codes[0] == "print") {
            if (codes[1][0] == '"') {
                for(int i=1;i<codes.size();i++) {
                    cout << codes[i] << " ";
                } cout << endl;
            }
        }
    }
    return;
}

int main(int argc,char *argv[]) { //
    signal(SIGINT,sigintHandle);
    char s[2147];
    vector<string> lines;
    if(argc == 1) {
        return Shell();
    } else {
        if(strcmp("--version",argv[1]) == 0 || strcmp("-V",argv[1]) == 0) {
            cout << "ECScript " << VER << "\n";return 0;
        } else {
         //   FILE a = fopen();
            ifstream f(argv[1],ios::in);
            int line = 1; //计数
            while(f.getline(s,2147)){ //读源文件内容
                //cout << s << endl;
                string s2(s);
                Run(s2,line);
                line++;
            }
            f.close();
            //Start();
        }
    }
}
#ifdef __cplusplus
//}
#endif