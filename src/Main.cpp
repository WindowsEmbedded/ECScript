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
#define VER 0.1
enum Bool{True=1,False=0};

int main(int argc,char *argv[]);
int Shell();
using namespace std;
string Codes[214753]; //字符串数组

int Shell() {
    cout << "Welcome to ECScript "<<VER<<"\n";
    return 0;
}

int main(int argc,char *argv[]) {
    char s[214753];
    vector<string> lines;
    if(argc == 1) {
        return Shell();
    } else {
        if(strcmp("--version",argv[1]) == 0 || strcmp("-V",argv[1]) == 0) {
            cout << "ECScript " << VER << "\n";return 0;
        } else {
         //   FILE a = fopen();
            ifstream f(argv[1],ios::in);
            int i = 0; //计数
            while(f.getline(s,214752)){ //读源文件内容
                //cout << s << endl;
                Codes[i] == s;
                i++;
            }
            f.close();
            
        }
    }
}
#ifdef __cplusplus
//}
#endif