/*************************************************************************
  > File Name: 8.c
  > Author: houxiangfei
  > Mail: xiangfei_hou@accton.com.cn
  > Created Time: Thu 21 Feb 2019 05:37:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define INT_MAX  (2147483647)
#define INT_MIN  (-2147483648)

int myAtoi(char* str) {

	if (str == NULL)
		return 0;
	long ret = 0;
	int flag = 1;
	char buf[40] ={0};

	while(*str ==' ')
	{
		str++;
	}
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	if (*str == '+'  && flag > 0)
	{
		str++;
	}
	while(*str =='0')
	{
		str++;
	}
	int i = 0;
	while(*str >= '0' && *str <= '9')
	{
		buf[i] = *str;
		str++;
		i++;
		if(i>10)
		{
			if(flag > 0)
			{
				return INT_MAX;
			}
			else
			{
				return INT_MIN;
			}
		}
	}



	int j = 0;
	while(i>0)
	{
		ret = ret*10+buf[j]-'0';
		i--;
		j++;
	}
	ret = ret*flag;
	if(ret > INT_MAX)
	{
		return INT_MAX;
	}
	if(ret < INT_MIN)
	{
		return INT_MIN;
	}
	return (int)ret;

}
int main(int argc, const char *argv[])
{
	char buf[40] ={0};
	int ret = 0;
	scanf("%s",buf);
	ret = myAtoi(buf);
	printf("%d\r\n",ret);
	return 0;
}

