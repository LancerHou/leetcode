/*************************************************************************
  > File Name: 9.c
  > Author: houxiangfei
  > Mail: xiangfei_hou@accton.com.cn
  > Created Time: Thu 21 Feb 2019 07:00:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int x;
	int true = 1;
	int false = 0;

	scanf("%d",&x);


	if(x < 0)
	{
		return false;
	}
	char buf[20] = {0};
	int i = 0;
	int j = 0;
	while(x>0)
	{
		buf[j] = x % 10;
		x = x / 10;
		j++;
	}

	j--;
	while(j > i)
	{
		if(buf[i] == buf[j])
		{
			i++;
			j--; 
		}
		else
		{
			return false;
		}
	}
	return true;
}

