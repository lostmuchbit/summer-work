#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define Max 10001

/*int longestCommonSubsequence(char * text1, char * text2)
{
    int len1=strlen(text1);
    int len2=strlen(text2);
    int dp[len2+1];
    memset(dp,0,sizeof(int)*(len2+1));
    for(int i=1;i<=len1;i++)
    {   
        int pre=0;
        for(int j=1;j<=len2;j++)
        {        
            int temp=dp[j];
            if(text1[i-1]==text2[j-1]) dp[j]=pre+1;
            else dp[j]=fmax(dp[j],dp[j-1]);
            pre=temp;
        }
    }
    return dp[len2];
}*/

/*状态表示：dp[i][j] text1[0~i] 与 text2[0~j]的最长公共子序列的长度; 属性：Max;
状态计算：找最后一个不同点。text1的第i位字符和text2的第j位字符是否在这个最长公共子序列中
分别用00, 01, 10, 11简要表示四种状态
00: 不包含text1[i]与text2[j]，所以dp[i][j] = dp[i - 1][j - 1]
11: 包含text1[i]与text2[j]，所以dp[i][j] = dp[i - 1][j - 1] + 1;这种情况有一个限制就是text1[i]==text2[j]。
01: 不包含text1[i], 包含text2[j]。可能想当然的认为dp[i][j] = dp[i - 1][j];
但是按照定义：dp[i - 1][j] text1[0~i - 1] 与 text2[0~j]的最长公共子序列的长度。
这个最长公众子序列可能包含text2[j]，也可能不包含text2[j]。也就是说dp[i - 1][j]表示的情况多于01表示的情况。
一般情况下，应该是不重复不遗漏。但是在计算最大值是只需要满足不遗漏，因为重复对于求最大值来说无影响。
综上所述，01情况可以用dp[i - 1][j]来表示。
10: 同理，该情况可以用dp[i][j - 1]。
最后就是求这几种情况的最大值。
Tips:可以发现dp[i - 1][j - 1]肯定是dp[i][j - 1]或者dp[i - 1][j]的子集，因此又可以去掉。
初始化：求的是最长的公众子序列，就初始化为0吧
状态转移中有i - 1， 所以显然应该初始化一下与首字母相关的
dp[0][0] = text1[0] == text2[0] ? 1 : 0;
dp[0][1 ~ n - 1] 就是说一定得包含text1[0]，不包含就只能是0了。
dp[1 ~ m - 1][0] 同理
*/
int longestCommonSubsequence(char * text1, char * text2)
{
    int len1=strlen(text1);
    int len2=strlen(text2);

    int dp[len1+1][len2+1];
    memset(dp,0,sizeof(int)*(len1+1)*(len2+1));

    for(int i = 1; i <=len1; i++) 
        for(int j = 1; j <= len2; j++) 
            if(text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = fmax(dp[i][j - 1], dp[i - 1][j]);

    return dp[strlen(text1)][strlen(text2)];   
}

int main()
{
	char text1[Max],text2[Max];
    
    printf("输入text1：");
    scanf("%s",text1);
    printf("输入text2：");
    scanf("%s",text2);
    printf("最长公共子序列长度为:%d",longestCommonSubsequence(text1,text2));
    return 0;
 } 
