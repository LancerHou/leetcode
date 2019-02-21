/*************************************************************************
	> File Name: 6.c
	> Author: houxiangfei
	> Mail: xiangfei_hou@accton.com.cn
	> Created Time: Fri 16 Nov 2018 02:45:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int count_of_buf = 0;


typedef struct queue_of_malloc     //竖排记录元素，然后横排取出
{
    struct queue_of_malloc * next;
    char *buf;
}queue_of_malloc;

queue_of_malloc s_head = {NULL,NULL};



char* convert(char* s, int numRows) 
{
    if(numRows == 1)
    {
	return s;
    }
    count_of_buf = strlen(s);
    char *res = (char*)malloc(count_of_buf+1);
    int num_of_struct = 0;
    int k = 0;
    int i = 0;                         //记录有多少列
    int j = 0;
    queue_of_malloc *p = NULL;
    p = &s_head;

    while(count_of_buf > 0)
    {
	p->buf = (char *)malloc(numRows);
	memset(p->buf,0,numRows);
	if(i % (numRows-1) == 0)
	{
	    for(j=0; j<numRows; j++)
	    {
		p->buf[j] = *s;
		s++;
		count_of_buf--;
		if(count_of_buf == 0)
		{
		    goto sort_again;
		}
	    }
	}
	else
	{
	    int tmp = 0 ;
	    tmp = numRows -(i % (numRows -1)) -1;
	    p->buf[tmp] = *s;
	    s++;
	    count_of_buf--;
	    if(count_of_buf == 0)
	    {
		goto sort_again;
	    }
	}

	i++;
	p->next = (queue_of_malloc *)malloc(sizeof(queue_of_malloc));
	p = p->next;
	p->buf = NULL;
	p->next = NULL;
    }

sort_again:
    num_of_struct = i;
    i = 0;
    j = 0;
    for(i=0; i < numRows; i++)
    {
	p = &s_head;
	for(j=0; j <= num_of_struct; j++)
	{
	    if(p->buf[i] != 0)
	    {
		res[k] = p->buf[i];
		k++;
	    }
	    p=p->next;
	}
    }
    res[k] = '\0';
    return res;
	        
}

int main(int argc, const char *argv[])
{
    char buf[5000] = {0};
    char *result = NULL;
    int num = 0;
    scanf("%s %d",buf,&num);
    result = convert(buf,num);
    printf("%s\n",result);
    return 0;
}

