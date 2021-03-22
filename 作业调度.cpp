#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct JCB   //������ҵ���ƿ�JCB�ṹ��
{
	int ID;            //��ҵ��ʶ��ID
	float requesttime;   //��ҵ��������Ҫʱ��requesttime
	int runtime;        //��ҵʵ������ʱ��runtime
	int arrivetime;      //��ҵ����ʱ��arrivetime
	int starttime;       //��ҵ��ʼʱ��starttime
	int finishtime;       //��ҵ���ʱ��finishtime
	float zhuantime;   //��ҵ��תʱ��zhuantime
}JCB;
#define N 100        //�궨��
JCB jcb[N];          //������ҵ������
int jcbnum;          //������ҵ�����
void init();         //��ʼ������
void FCFS();         //�����ȷ����㷨
void SJF();          //����ҵ�����㷨
void HRN();          //����Ӧ���㷨
void init()          //��ʼ����ҵ���ȿ�
{ 
	int j=0;
	int req;
	while(j<=0||j>2000)       //ʵ����ҵ������
	{
		cout<<"��������ҵ����:(1--2000)";
		cin>>j;	
	}
	jcbnum=j;              
	for(j=0;j<jcbnum;j++)    //ʵ����ҵ��ѭ��ִ��
	{
		cout<<"�������"<<j+1<<"����ҵ���������ʱ�䣬Ĭ�ϴﵽʱ��Ϊ"<<j<<endl;
		cin>>req;
        jcb[j].ID=j+1;         
		jcb[j].requesttime=req;
		jcb[j].arrivetime=j;   
		jcb[j].starttime=0;    
		jcb[j].finishtime=0;   
		jcb[j].zhuantime=0; 
	}
}

void FCFS() //�ȵ��ȷ����㷨��ʵ��
{
	int i;float a,b;b=a=0;
	cout<<"��ѡ�����ȵ��ȷ����㷨������ҵ���ȣ��������:"<<endl;   
	cout<<"��ҵ ����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��"<<endl; 
	for(i=0;i<jcbnum;i++)              
	{   
		int runtime=0;  
	    jcb[i].finishtime=jcb[i].starttime+jcb[i].requesttime; 
		jcb[i].zhuantime=jcb[i].finishtime-jcb[i].arrivetime;
		cout<<"  "<<jcb[i].ID<<"\t "<<jcb[i].arrivetime<<"\t "<<jcb[i].requesttime<<"\t  "<<jcb[i].starttime<<"\t   "<<jcb[i].finishtime<<"\t   "<<jcb[i].zhuantime<<"\t   ";  /*�����ҵ����ҵ ����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ��*/
        cout<<jcb[i].zhuantime/jcb[i].requesttime<<endl;
	    jcb[i+1].starttime=jcb[i].finishtime; 
        a+=jcb[i].zhuantime;
		b+=jcb[i].zhuantime/jcb[i].requesttime;
	}
	cout<<"ƽ����תʱ�䣺"<<a/jcbnum<<endl;
	cout<<"ƽ����Ȩ��תʱ�䣺"<<b/jcbnum<<endl;
}


void SJF()//����ҵ�����㷨
{
	int i,j,r,c,fin=0;  float a,b;a=b=0;c=jcbnum;
	cout<<"��ѡ���ö���ҵ�����㷨������ҵ���ȣ��������"<<endl;
	cout<<"��ҵ ����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��"<<endl;
	while(jcbnum>0)      
	{
		r=0;
		for(i=0;i<jcbnum;i++)
			if(jcb[r].requesttime>jcb[i].requesttime)  
				r=i;
		jcb[r].starttime=fin;
        jcb[r].finishtime=fin+jcb[r].requesttime;
        jcb[r].zhuantime=jcb[r].finishtime-jcb[r].arrivetime;
		a+=jcb[r].zhuantime;
		b+=jcb[r].zhuantime/jcb[r].requesttime;
		cout<<"  "<<jcb[r].ID<<"\t "<<jcb[r].arrivetime<<"\t "<<jcb[r].requesttime<<"\t  "<<jcb[r].starttime<<"\t   "<<jcb[r].finishtime<<"\t   "<<jcb[r].zhuantime<<"\t   ";
		cout<<jcb[r].zhuantime/jcb[r].requesttime<<endl;
		fin+=jcb[r].requesttime;
		for(j=r;j<jcbnum-1;j++)
		{
			jcb[j].ID=jcb[j+1].ID;
		    jcb[j].requesttime=jcb[j+1].requesttime;
			jcb[j].arrivetime=jcb[j+1].arrivetime;  
		
	}
		
	jcbnum--;	
	}cout<<"ƽ����תʱ�䣺"<<a/c<<endl;
	cout<<"ƽ����Ȩ��תʱ�䣺"<<b/c<<endl;
	cout<<endl;	
}
void HRN()//����Ӧ���㷨
{
	int i,j,r,c;
	float a,b;
	a=b=0;
	c=jcbnum;
	int waittime=0;     //���̵ȴ����������ʱ��
	cout<<"��ѡ�����Ӧ�������㷨������ҵ���ȣ��������:"<<endl;
	cout<<"��ҵ ����ʱ�� ����ʱ�� ��ʼʱ�� ���ʱ�� ��תʱ�� ��Ȩ��תʱ��"<<endl;
	while(jcbnum>0)
	{
		r=0;
		for(i=0;i<jcbnum;i++)    //ѡ����Ӧ����ߵĽ���
			if((waittime+0.0)/jcb[r].requesttime>((waittime+0.0)/jcb[i].requesttime))
				r=i;
		jcb[r].starttime=waittime;
        jcb[r].finishtime=waittime+jcb[r].requesttime;
        jcb[r].zhuantime=jcb[r].finishtime-jcb[r].arrivetime;
		a+=jcb[r].zhuantime;
		b+=jcb[r].zhuantime/jcb[r].requesttime;
		cout<<"  "<<jcb[r].ID<<"\t "<<jcb[r].arrivetime<<"\t "<<jcb[r].requesttime<<"\t  "<<jcb[r].starttime<<"\t   "<<jcb[r].finishtime<<"\t   "<<jcb[r].zhuantime<<"\t   ";
		cout<<jcb[r].zhuantime/jcb[r].requesttime<<endl;
		waittime+=jcb[r].requesttime;
		for(j=r;j<jcbnum-1;j++)
		{
			jcb[j].ID=jcb[j+1].ID;
	        jcb[j].requesttime=jcb[j+1].requesttime;
			jcb[j].arrivetime=jcb[j+1].arrivetime;
		}
		jcbnum--;	
	} cout<<"ƽ����תʱ�䣺"<<a/c<<endl;
	cout<<"ƽ����Ȩ��תʱ�䣺"<<b/c<<endl;
	cout<<endl;	
}


//������
int main()
{   bool flog=1;
	int i=0;
	char ch;
   	cout<<"********************************"<<endl;
	cout<<" |          1:�����ȷ���        |"<<endl;
	cout<<" |          2:����ҵ����        |"<<endl;
	cout<<" |          3:�����Ӧ������    |"<<endl;
	cout<<"********************************"<<endl;
    while(flog){                    
        init();	
	a1:	cout<<"��ѡ����Ҫ����ѡ��(1--3):";
		cin>>i;	
		if(i>=0&&i<=3){
		switch(i)             
		{
			case 1:FCFS();break;   //ѡ��"1"��ʱ����õ���FCFS�㷨
			case 2:SJF();break;    //ѡ��"2"��ʱ����õ���SJF�㷨
            case 3:HRN();break;    //ѡ��"3"��ʱ����õ���HRN�㷨
		}
		cout<<endl;	}
		else{ cout<<"����������������룡"<<endl;	goto  a1;}
		cout<<"�Ƿ���Ҫ����(N/Y)?:";    //�Ƿ����ִ��
		cin>>ch;
	    if(ch=='y'||ch=='Y') flog=1; 
		else flog=0;
	}
	} 

