#include <iostream>
#include<cstdio>
using namespace std;

void revstr1(char str[],int l,int h);
void partition(char str[],int l,int h);
int strlen(char str[]);

void revstr1(char str[],int l,int h){
    char c;
    int k=0;
    for(int i=l;i<(h+l)/2;i++){
       c=str[i];
       str[i]=str[h-k-1];
       str[h-k-1]=c;
       k++;
    }
   
}

void partition(char str[],int l,int h){
    if(h-l>=2){
       int m=(l+h)/2;
        revstr1(str,l,m);
        revstr1(str,m,h);
        partition(str,l,m);
        partition(str,m,h);
    }
    
}

int main() {
	char str[100];
	scanf("%[^\n]s",str);
	int p=strlen(str);
	partition(str,0,p);
	
	cout<<p<<endl;
	cout<<str;
	

	
	return 0;
}
int strlen(char str[])
{

  int l=0;
  while(str[l++]!='\0');
  return l-1;


}
