/*************************************************************************
	> File Name: 11.c
	> Author: houxiangfei
	> Mail: xiangfei_hou@accton.com.cn
	> Created Time: Wed 27 Feb 2019 02:01:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) 
{
	int *left = height;
	int *right = height + heightSize - 1;
	int max_size = 0;
	int tmp = 0;
	int i = 1;
	int j = heightSize;

	while(left < right)
	{
		if(*left < *right)
		{
			tmp = (*left) * (j - i);
			left++;
			i++;
		}
		else
		{
			tmp =(j - i) * (*right);
			right--;
			j--;
		}
		if(tmp > max_size)
		{
			max_size = tmp;
		}
	}
	return max_size;
}



int main(int argc, const char *argv[])
{
	int a[9] = {1, 8, 6, 2, 5, 4, 3, 8, 7};
	int size = sizeof(a)/sizeof(a[0]);
	int area = 0;

	area = maxArea(a,size);
	printf("maxArea = %d\n",area);
	return 0;
}

