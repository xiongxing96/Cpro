/*
	求最大回文子串 
**/ 
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#define Min(a,b) a>b?b:a  
#define Max(a,b) a>b?a:b  
using namespace std;  
int Len[3000005];  
char str[3000005],s[3000005];  
int n,mx,id,len;  

void init(){  
    int k=0;  
    str[k++] = '$';  
    for(int i=0;i<len;i++){  
        str[k++]='#';  
        str[k++]=s[i];  
    }  
    str[k++]='#';  
    len=k;  
}  

int Manacher(){  
  Len[0] = 0;  
  int sum = 0;  
  mx = 0;  
  for(int i=1;i<len;i++){  
    if(i < mx) Len[i] = Min(mx - i, Len[2 * id - i]);  
    else Len[i] = 1;  
    while(str[i - Len[i]]== str[i + Len[i]]) Len[i]++;  
    if(Len[i] + i > mx){  
      mx = Len[i] + i;  
      id = i;  
      sum = Max(sum, Len[i]);  
    }  
  }  
  return (sum - 1);  
}  

int main()  
{  
  scanf("%d",&n);  
  while(n--){  
    memset(str,0,sizeof(str));
    scanf("%s",s);  
    len = strlen(s);  
    init();  
    int temp = Manacher();  
    printf("%d\n",temp);  
  }  
  return 0;  
}  
