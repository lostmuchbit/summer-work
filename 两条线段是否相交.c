#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

const int MAXN = 2100;
struct Point
{
    double x,y;
}line[MAXN][2];

double mult(Point p0,Point p1,Point p2) //叉积计算,p0为公用节点
{
    return (p0.x - p1.x) * (p0.y - p2.y) - (p0.y - p1.y) * (p0.x - p2.x);
}

//aa、bb属于同一个矩形 cc、dd属于同一个矩形 相交返回true，不相交返回false
bool Judge(Point aa,Point bb,Point cc,Point dd)
{
    //判断两个形成的矩形不相交
   if(fmax(aa.x , bb.x) < fmin(cc.x , dd.x)) return false;
   if(fmax(aa.y , bb.y) < fmin(cc.y , dd.y)) return false;
   if(fmax(cc.x , dd.x) < fmin(aa.x , bb.x)) return false;
   if(fmax(cc.y , dd.y) < fmin(aa.y , bb.y)) return false;

   //现在已经满足快速排斥实验，那么后面就是跨立实验内容(叉积判断两个线段是否相交)
   if(mult(aa,cc,bb) * mult(aa,bb,dd) < 0) return false; //正确的话也就是aa,bb要在cc或者dd的两边
   if(mult(cc,aa,dd) * mult(cc,dd,bb) < 0) return false;
   return true;
}

void finish()
{
	char sure;
	printf("Are you sure to exit?(y/n):");
	getchar();
	sure=getchar();
	if(sure=='y'||sure=='Y')
	exit(0);
} 

int main()
{
    
    while(1)
    {   
	    int n=2;
	    
        bool flag = true;
        for(int i = 0;i < n;i ++)
        {
        	printf("输入第%d条线段:",i+1);
        	scanf("%lf%lf%lf%lf",&line[i][0].x,&line[i][0].y,&line[i][1].x,&line[i][1].y);
		}
        
        
        for(int i = 0;i < n;i ++)
        for(int j = i+1;j < n;j ++)
        {
            if(Judge(line[i][0],line[i][1],line[j][0],line[j][1])) // 判断两条线段是否相交
            {
                flag = false;
                break;
            }
			 if(!flag) break;
        }
        if(!flag) printf("两线段相交!\n");
        else printf("两线段不相交!\n");
        finish();
    }
    return 0;
}
