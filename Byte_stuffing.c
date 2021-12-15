#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *Receiver(char data2[],char data3[],char ESC[],char flag[])
{
  printf("********Frame is********\n");
  printf("%s\n",data2);
  int i,temp,j=0,m=0,k,l;
  char data[500]={};
  char flag_new[100]={};
  char ESC_new[100]={};
  char receiver[500]={};
  for(i=strlen(flag)-1;i>=0;i--)
  {
   flag_new[j]=flag[i];
   j++;
  }
 j=0;
 for(i=strlen(ESC)-1;i>=0;i--)
  {
   ESC_new[j]=ESC[i];
   j++;
  }
  for(i=strlen(data2)-strlen(flag_new)-1;i>=strlen(flag_new);i--)
   {
      l=i;
      for(j=0;j<strlen(flag_new);j++)
       {
	 if(data2[i]==flag_new[j])
          {
            temp=1;
            i--;
          }
   	 else
          {
	    i=l;
            for(j=0;j<strlen(ESC_new);j++)
          {
            if(data2[i]==ESC_new[j])
            {
	     temp=1;
             i--;
	    }
            else
            {
	     temp=0;
	     break;
            }
          }
         }
         if(temp==0)
	 break;
       }
        if(temp==1)
        {
	  for(k=i;k>i-strlen(flag_new);k--)
           {
             data[m]=data2[k];
             m++;
           }
          i=k+1;
        }
       else
       {
         data[m]=data2[l];
         m++;
	 i=l;
       }
   }  
    j=0;
    for(i=strlen(data)-1;i>=0;i--)
     {
       receiver[j]=data[i];
       j++;
     }
    printf("********Data part at the receiver end excluding flags is ********\n");    
    printf("%s\n",receiver);
 }
int main()
{
  char data1[500]={};
  char data2[500]={};
  char data3[500]={};
  char data4[500];
  char flag[100];
  char c;
  char a[500];
  char ESC[]={'0','0','0','1','1','0','1','1','\0'};
  int i,j=0,k=0,temp,count=0,l,flag1=0,m=0,n=0,ascii;
  printf("Enter the data in string format\n");
  scanf("%[^\n]s",data4);
  for(k=0;k<strlen(data4);k++)
   {
     ascii=(int) data4[k];
    for(i=0;ascii>0;i++)    
	{    
	 m=ascii%2;
         c=m+'0';
         a[j]=c;   
	 ascii=ascii/2;
         j++;    
	} 
    
   }
  m=0;
  for(k=j-1;k>=0;k--)
 {
  data1[m]=a[k];
  m++;
 }
  strcat(data3,data1);
  printf("Enter the flag in string format\n");
  scanf("%s",flag);
  k=0;
 for(i=0;i<strlen(data1);)
 {
   l=i;
  for(j=0;j<strlen(flag);j++)
   {
     if(data1[i]==flag[j] && data1[i]!='\0')
      {
         i++;
         temp=1;
         flag1=1;
      }
     else
    {
      i=l;
      for(j=0;j<strlen(ESC);j++)
     {
      if(data1[i]==ESC[j] && data1[i]!='\0')
      {
         i++;
         temp=1;
         flag1=0;
      }
      else
       {
        temp=0;
        break;
       }
     }
     if(temp==0)
     {
      break;
     }
     
    }
   }
   if(temp==1)
   {
     for(k=strlen(data1)-1;k>=i;k--)
     {
        data1[k+8]=data1[k];
     }
       for(k=0;ESC[k]!='\0';k++)
      {
       data1[i]=ESC[k];
       i++;
      }
   }
  else
  {
    i=l+1;
  }
   }
   printf("********Data part at the sender end excluding flags is ********\n");
   printf("%s\n",data1);
  strcat(data1,flag);
  strcat(data2,flag);
  strcat(data2,data1);
  Receiver(data2,data3,ESC,flag);
 }
