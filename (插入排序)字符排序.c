/*思路：对数组插入排序升序，字符串就正常了*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h" 

 void restoreString(char *s,int *indices,int indicesSize)
{
      for(int i=1;i<indicesSize;i++)
      {
      	int tmp=indices[i],tep=s[i];
      	int j;
      	for(j=i-1;j>=0&&indices[j]>tmp;j--)
		  indices[j+1]=indices[j],s[j+1]=s[j];
		  indices[j+1]=tmp,s[j+1]=tep; 
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
