/*************************************************************************
	> File Name: 7.c
	> Author: houxiangfei
	> Mail: xiangfei_hou@accton.com.cn
	> Created Time: Fri 04 Jan 2019 05:19:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
int reverse(int x) {
	int res[32] = {0};
	int num = 0;
	long y = x;
	if(x >= pow(2,31)-1 || x  <= -1*pow(2,31))
	{
		return 0;
	}
	if(x < 0)
	{
		res[31] = -1;
		y = x * -1;
	}
	else
	{
		res[31] = 1;
	}
	res[num]=y % 10;
	num++;
	while((y = y / 10) != 0)
	{
		res[num]=y % 10;
		num++;
	}

	y = 0;
	int j = 0;
	num--;
	while(num >= 0)
	{
		y += res[j]*pow(10,num);
		num--;
		j++;
	}

	if(y > pow(2,31)-1 || y*res[31] < -1*pow(2,31))
	{
		return 0;
	}
	else
	{
		return (int)y*res[31];
	}
		    
		    
		    
}
int main(int argc, const char *argv[])
{
	int x = 0;
	scanf("%d",&x);

	x=reverse(x);

	printf("%d\n",x);



	return 0;
}

