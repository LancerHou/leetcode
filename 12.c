/*************************************************************************
  > File Name: 12.c
  > Author: houxiangfei
  > Mail: xiangfei_hou@accton.com.cn
  > Created Time: Wed 27 Feb 2019 02:25:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
char* intToRoman(int num) 
{
	int a[4] = {0};
	int i = 0;
	char *p = (char * ) malloc(40*sizeof(char));
	char *start = p;
	memset(p,0,40);
	while(num > 0)
	{
		a[i] = num % 10;
		num = num / 10;
		i++;
	}
	if(a[3] > 0)
	{
		while(a[3] < 4 && a[3] > 0)
		{
			*p = 'M';
			p++;
			a[3] -= 1;
		}

	}






	if(a[2] > 0)                                  
	{                                             
		if(a[2] == 4)                             
		{                                         
			*p = 'C';                             
			p++;                                  
			*p = 'D';                             
			p++;
		}                                         
		if(a[2] == 9)                             
		{                                         
			*p = 'C';                             
			p++;                                  
			*p = 'M';                             
			p++;
		}                                         
		while(a[2] < 4 && a[2] > 0)               
		{                                         
			*p = 'C';                             
			p++;                                  
			a[2] -= 1;                            
		}                                         

		if(a[2] >= 5 && a[2] != 9)                              
		{                                         
			*p = 'D';                             
			p++;                                  
		}                                         
		while(a[2] > 5 && a[2] < 9)               
		{                                         
			*p = 'C';                              
			p++;                                  
			a[2] -= 1;                            
		}                                         
	}



	if(a[1] > 0)                                  
	{                                             
		if(a[1] == 4)                             
		{                                         
			*p = 'X';                             
			p++;                                  
			*p = 'L';                             
			p++;
		}                                         
		if(a[1] == 9)                             
		{                                         
			*p = 'X';                             
			p++;                                  
			*p = 'C';                             
			p++;
		}                                         
		while(a[1] < 4 && a[1] > 0)               
		{                                         
			*p = 'X';                             
			p++;                                  
			a[1] -= 1;                            
		}                                         

		if(a[1] >= 5 && a[1] != 9)                              
		{                                         
			*p = 'L';                             
			p++;                                  
		}                                         
		while(a[1] > 5 && a[1] < 9)               
		{                                         
			*p = 'X';                              
			p++;                                  
			a[1] -= 1;                            
		}                                         
	}                                             


	if(a[0] > 0)                                  
	{                                             
		if(a[0] == 4)                             
		{                                         
			*p = 'I';                             
			p++;                                  
			*p = 'V';
			p++;
		}                                         
		if(a[0] == 9)                             
		{                                         
			*p = 'I';                             
			p++;                                  
			*p = 'X';                             
			p++;
		}                                         
		while(a[0] < 4 && a[0] > 0)               
		{                                         
			*p = 'I';                             
			p++;                                  
			a[0] -= 1;                            
		}                                         

		if(a[0] >= 5 && a[0] != 9)                              
		{                                         
			*p = 'V';                             
			p++;                                  
		}                                         
		while(a[0] > 5 && a[0] < 9)               
		{                                         
			*p = 'I';                              
			p++;                                  
			a[0] -= 1;                            
		}                                         
	}       
	*p = '\0';
	return start;

}
int main(int argc, const char *argv[])
{
	int num = 0;
	char *p = NULL;
	scanf("%d",&num);
	p = intToRoman(num);
	printf("%s\n",p);
	free(p);
	return 0;
}

