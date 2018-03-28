#include <iostream>
using namespace std;

// 实现一个函数，把字符串中的每个空格替换成"%20"。
void replace(char string[], int length){ //length为string容纳长度
    if(string==nullptr || length<=0) return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;

    while(string[i]!='\0'){
        ++originalLength;
        if(string[i]==' ')
            ++numberOfBlank;
        ++i;
    }
    cout<<originalLength<<" "<<numberOfBlank<<endl;

    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length){
        cout<<"超出字符串允许长度"<<endl;
        return;
    }

    // 两个指针(从/0开始复制)
    int indexOrigin = originalLength;
    int indexNew = newLength;

    while(indexOrigin>=0 && indexNew > indexOrigin){
        // 如果复制点不是空格
        if(string[indexOrigin]!=' '){
            string[indexNew--]=string[indexOrigin];
        } else{
            string[indexNew--]='0';
            string[indexNew--]='2';
            string[indexNew--]='%';
        }
        --indexOrigin;
    }
}
 
int main(){
    
    // abort trap:6 数组越界； 注意字符串的长度！！
    char string[100] = "hello world    dddxxa";
    replace(string, 100);
    int i=0;
    while(string[i]!= '\0' ){
        cout<<string[i];
        i++;
    }
}