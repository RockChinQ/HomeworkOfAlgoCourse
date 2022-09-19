#include <iostream>
#include <malloc.h>

using namespace std;

struct Table{
    int table[10];
    int length;
};

void deleteElement(Table *t,int x){
    for(int i=0;i<t->length;i++){
        if(t->table[i]==x){
            for(int j=i;j<t->length-1;j++){
                t->table[j]=t->table[j+1];
            }
            t->length--;
            break;
        }
    }
}

int main(){

    Table *t=(Table *)malloc(sizeof(Table));
    

    int x=6;
    t->length=10;
    for(int i=0;i<t->length;i++){
        t->table[i]=i+1;
        cout<<t->table[i]<<" ";
    }
    cout<<endl;

    deleteElement(t,x);

    for(int i=0;i<t->length;i++){
        cout<<t->table[i]<<" ";
    }
}