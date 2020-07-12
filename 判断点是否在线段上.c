/*问题：没什么问题*/ 
/*思路：结构体定义点，while语句中循环判断，用exit结束循环，onSegement函数中判断点是否在线段上*/ 
#include "stdio.h"
#include "stdlib.h"

struct point
{
    double x;  //x坐标
    double y;  //y坐标

};  //定义点

void finish()
{
	char sure;
	printf("Are you sure to exit?(y/n):");
	getchar();
	sure=getchar();
	if(sure=='y'||sure=='Y')
	exit(0);
} 


//判断点是否在线上，在返回1，不在返回0
int onSegement(point p1,point p2,point Q)
{
    double maxx,minx,maxy,miny;

    maxx = p1.x >p2.x ?p1.x :p2.x ;    //矩形的右边长
    minx = p1.x >p2.x ?p2.x :p1.x ;     //矩形的左边长
    maxy = p1.y >p2.y ?p1.y :p2.y ;    //矩形的上边长
    miny = p1.y >p2.y ?p2.y :p1.y ;     //矩形的下边长

    if( ((Q.x -p1.x )*(p2.y -p1.y) == (p2.x -p1.x) *(Q.y -p1.y)) && ( Q.x >= minx && Q.x <= maxx ) && ( Q.y >= miny && Q.y <= maxy))
        return 1;
    else
        return 0;
}
int main()
{
    struct point P1,P2,Q;

    while(1)
	{
		printf("输入线段的端点P1:");
        scanf("%f%f",&P1.x ,&P1.y);
        printf("\n");

        printf("输入线段的端点P2:");
        scanf("%f%f",&P2.x ,&P2.y );
        printf("\n");
        
        printf("输入需判断的点 :");
        scanf("%f%f",&Q.x ,&Q.y );
        printf("\n");

		
		if(((P1.x ==P2.x )&&(P1.y ==P2.y ))||((P1.x ==Q.x)&&(P1.y ==Q.y))||((P2.x ==Q.x)&&(P2.y ==Q.y)))//防止三个一样的点 
		{
			printf("三点是同一点，重输\n"); 
		    continue;
		}

        if( onSegement(P1,P2,Q) )
        {
           printf("point on the line\n");
        }
        else
        {
           printf("point not on the line\n");
        }
        
        finish(); 
        
        
	} 
    
    
    return 0;

}
