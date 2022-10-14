//5. 实验一：十进制数到N进制数的转换
#include <iostream>
#include <string>

using namespace std;

const char symbols[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convertBase(int num,int base){
    char result[32]={0};
    int index=0;

    while(1){
        if(num<base){
            result[index]=symbols[num];
            break;
        }else{
            int remain=num%base;
            num=num/base;
            result[index]=symbols[remain];
        }
        index++;
    }
    for(int i=index;i>=0;i--){
        cout<<result[i];
    }
}
int main(){
    int num;
    cin>>num;

    int N;
    cin>>N;

    convertBase(num,N);
}