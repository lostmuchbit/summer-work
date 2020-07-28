/*思路：对数组选择排序升序，字符串也就正常了*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void restoreString(char * s, int* indices, int indicesSize)
{
	int index;
	for(int i=0;i<indicesSize-1;i++)
	{
		index=i;
		for(int j=i;j<indicesSize-1;j++)
		if(indices[j]>indices[j+1])
		index=j+1;
		int tmp=indices[i];
		indices[i]=indices[index];
		indices[index]=tmp;
		int tep=s[i];
		s[i]=s[index];
		s[index]=tep;
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
