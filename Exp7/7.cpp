//7. 实验一：判断一个字符串是否是回文
//确定字符串长度，挨个进行验证
#include <iostream>

using namespace std;

int main(){
    char text[100];
    cin>>text;//读入字符串

    int len=0;
    //扫描确定长度
    while(text[len]!='\0'){
        len++;
    }
    for(int i=0;i<len/2+1;i++){
        if(text[i]!=text[len-i-1]){
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}