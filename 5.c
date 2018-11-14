/*************************************************************************
  > File Name: 5.c
  > Author: houxiangfei
  > Mail: xiangfei_hou@accton.com.cn
  > Created Time: 2018年11月13日 星期二 16时45分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>

int find_same_element(char *s, char ele, int left, int right)
{
	int i = left;
	int j = right;

	while(j > i)
	{
		if(s[j] == s[i])
		{
			return j;
		}
		j--;
	}
	return 0;

}

int is_moslems(char *s, int start, int end)   //成功返回长度，失败返回0
{
	if(end <= start)
		return 0;

	int i = start;
	int j = end;

	while(j > i)
	{
		if(s[i] == s[j])
		{
			i++;
			j--; 
		}
		else
		{
			return 0;
		}
	}
	return end-start+1;

}

int find_longest_moslems_of_element(char *s,char ele, int left)
{
	int len = strlen(s);
	int len_of_moslems = 1;
	int i = len;
	int start = left;
	int end = 0;

	for(i = len; i > left; i--)
	{
		end = find_same_element(s, ele, start, i);
		if(end > left)
		{
			if((len_of_moslems = is_moslems(s, start, end)) )
			{
				break;
			}
			else
			{
				i = end;
				end = 0;
			}
		}
		else
		{
			return 1;
		}
	}
	return len_of_moslems;

}

char* longestPalindrome(char* s) {
	int len = strlen(s);
	printf("len=%d\n",len);
	static char buf[1000] = {0};
	int i = 0;
	int j = 0;
	int count[1000] = {0};

	for (i =0 ; i < len; i++)
	{
		count[i] = find_longest_moslems_of_element(s,s[i],i);
		printf("count[%d]=%d \n",i,count[i]);
	}
	for(i= 0 ; i < len; i++)
	{
		if(count[i] > count[j])
		{
			j = i;
		}
	}
	
	printf("j=%d\n",j);

	strncpy(buf, s+j, count[j]);
	buf[count[j]] = '\0';
	printf("%s\n",buf);
	return buf;
}

int main(int argc, const char *argv[])
{
	char buf[1000] = {0};
	char *res = NULL; 
	scanf("%s",buf);
	res = longestPalindrome(buf);
	printf("%s",res);
	return 0;
}

