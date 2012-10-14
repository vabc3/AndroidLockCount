/*
 * =====================================================================================
 *       Filename:  a.c
 *        Created:  10/11/2012 10:54:47 AM
 *         Author:  Karata Lau (), vabc3h@gmail.com
 * =====================================================================================
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#define N 16

const char* base="123456789";
int prt(int num);
void make(char* str,int begin,int end);

void cob(int all,int num)
{
	char data[N];
	int sta[N];
	int p=0;
	int i;
	sta[0]=1;
	while(p>=0){
		if(p==num){
/*            for(i=0;i<num;i++)printf("%d",sta[i]);*/
/*            printf("\n");*/
			for(i=0;i<num;i++)data[i]=base[sta[i]-1];
			data[num]='\0';
/*            printf("%s\n",data);*/
			make(data,0,num);
			if(--p<0)break;
			sta[p]++;
		}
		if(sta[p]>all){
			if(--p<0)break;
			sta[p]++;
		}else{
			sta[p+1]=sta[p]+1;
			p++;
		}
	}
}

int main(int argc,char** argv)
{
	if(argc!=2){
		printf("%s <num>\n",*argv);
		return -1;
	}
	int num = atoi(*(argv+1));
	if(num<=0 || num>=10){
		printf("num must be >0 and < 10\n");
		return -1;
	}
	cob(9,num);
/*    prt(num);*/

	return 0;
}

inline void swap(char* str,int a,int b)
{
	if(a!=b){
		char tmp=str[a];
		str[a]=str[b];
		str[b]=tmp;
	}
}

void make(char* str,int begin,int end)
{
	int i;
/*    printf("%s %d %d\n",str,begin,end);*/
	if(begin+1==end)printf("%s\n",str);
	for(i=begin;i<end;i++){
		swap(str,begin,i);
		make(str,begin+1,end);
		swap(str,begin,i);
	}
}

int prt(int num)
{
	char data[N];
	strncpy(data,base,num);
	data[num]='\0';
/*    printf("[%s]\n",data);*/
	make(data,0,num);	
}
