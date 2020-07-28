/*思路：对数组冒泡升序，而字符串与数组一一对应，字符串也就顺序正常了*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void restoreString(char * s, int* indices, int indicesSize)
{
     for(int i=0;i<indicesSize;i++)
     for(int j=0;j<indicesSize-1-i;j++)
     if(indices[j]>indices[j+1])
     {
         int tmp;
         char tep;
         tmp=indices[j];
         indices[j]=indices[j+1];
         indices[j+1]=tmp;
         tep=s[j];
         s[j]=s[j+1];
         s[j+1]=tep;
     }
}

int main()
{
	int indicesSize;
	char* s=(char*)malloc(sizeof(int));
	printf("字符串："); 
	scanf("%s",s);
	indicesSize=strlen(s);
	int* indices=(int*)malloc(sizeof(int)*(indicesSize));
	printf("数组:");
	for(int i=0;i<indicesSize;i++)
	scanf("%d",&indices[i]);
	
	restoreString( s, indices, indicesSize);
	printf("%s",s);
	
	return 0;
	
} 
