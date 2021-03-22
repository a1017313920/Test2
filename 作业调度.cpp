#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct JCB   //定义作业控制块JCB结构体
{
	int ID;            //作业标识数ID
	float requesttime;   //作业运行所需要时间requesttime
	int runtime;        //作业实际运行时间runtime
	int arrivetime;      //作业到达时间arrivetime
	int starttime;       //作业开始时间starttime
	int finishtime;       //作业完成时间finishtime
	float zhuantime;   //作业周转时间zhuantime
}JCB;
#define N 100        //宏定义
JCB jcb[N];          //定义作业块数组
int jcbnum;          //定义作业块个数
void init();         //初始化函数
void FCFS();         //先来先服务算法
void SJF();          //短作业优先算法
void HRN();          //高响应比算法
void init()          //初始化作业调度块
{ 
	int j=0;
	int req;
	while(j<=0||j>2000)       //实现作业的输入
	{
		cout<<"请输入作业个数:(1--2000)";
		cin>>j;	
	}
	jcbnum=j;              
	for(j=0;j<jcbnum;j++)    //实现作业的循环执行
	{
		cout<<"请输入第"<<j+1<<"个作业的完成所需时间，默认达到时间为"<<j<<endl;
		cin>>req;
        jcb[j].ID=j+1;         
		jcb[j].requesttime=req;
		jcb[j].arrivetime=j;   
		jcb[j].starttime=0;    
		jcb[j].finishtime=0;   
		jcb[j].zhuantime=0; 
	}
}

void FCFS() //先到先服务算法的实现
{
	int i;float a,b;b=a=0;
	cout<<"你选择用先到先服务算法进行作业调度，结果如下:"<<endl;   
	cout<<"作业 到达时间 运行时间 开始时间 完成时间 周转时间 带权周转时间"<<endl; 
	for(i=0;i<jcbnum;i++)              
	{   
		int runtime=0;  
	    jcb[i].finishtime=jcb[i].starttime+jcb[i].requesttime; 
		jcb[i].zhuantime=jcb[i].finishtime-jcb[i].arrivetime;
		cout<<"  "<<jcb[i].ID<<"\t "<<jcb[i].arrivetime<<"\t "<<jcb[i].requesttime<<"\t  "<<jcb[i].starttime<<"\t   "<<jcb[i].finishtime<<"\t   "<<jcb[i].zhuantime<<"\t   ";  /*输出作业的作业 到达时间 运行时间 开始时间 完成时间 周转时间*/
        cout<<jcb[i].zhuantime/jcb[i].requesttime<<endl;
	    jcb[i+1].starttime=jcb[i].finishtime; 
        a+=jcb[i].zhuantime;
		b+=jcb[i].zhuantime/jcb[i].requesttime;
	}
	cout<<"平均周转时间："<<a/jcbnum<<endl;
	cout<<"平均带权周转时间："<<b/jcbnum<<endl;
}


void SJF()//短作业优先算法
{
	int i,j,r,c,fin=0;  float a,b;a=b=0;c=jcbnum;
	cout<<"你选择用短作业优先算法进行作业调度，结果如下"<<endl;
	cout<<"作业 到达时间 运行时间 开始时间 完成时间 周转时间 带权周转时间"<<endl;
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
	}cout<<"平均周转时间："<<a/c<<endl;
	cout<<"平均带权周转时间："<<b/c<<endl;
	cout<<endl;	
}
void HRN()//高响应比算法
{
	int i,j,r,c;
	float a,b;
	a=b=0;
	c=jcbnum;
	int waittime=0;     //进程等待处理机所用时间
	cout<<"你选择高响应比优先算法进行作业调度，结果如下:"<<endl;
	cout<<"作业 到达时间 运行时间 开始时间 完成时间 周转时间 带权周转时间"<<endl;
	while(jcbnum>0)
	{
		r=0;
		for(i=0;i<jcbnum;i++)    //选择响应比最高的进程
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
	} cout<<"平均周转时间："<<a/c<<endl;
	cout<<"平均带权周转时间："<<b/c<<endl;
	cout<<endl;	
}


//主函数
int main()
{   bool flog=1;
	int i=0;
	char ch;
   	cout<<"********************************"<<endl;
	cout<<" |          1:先来先服务        |"<<endl;
	cout<<" |          2:短作业优先        |"<<endl;
	cout<<" |          3:最高响应比优先    |"<<endl;
	cout<<"********************************"<<endl;
    while(flog){                    
        init();	
	a1:	cout<<"请选择你要做的选项(1--3):";
		cin>>i;	
		if(i>=0&&i<=3){
		switch(i)             
		{
			case 1:FCFS();break;   //选择"1"的时候调用的是FCFS算法
			case 2:SJF();break;    //选择"2"的时候调用的是SJF算法
            case 3:HRN();break;    //选择"3"的时候调用的是HRN算法
		}
		cout<<endl;	}
		else{ cout<<"输入错误，请重新输入！"<<endl;	goto  a1;}
		cout<<"是否想要继续(N/Y)?:";    //是否继续执行
		cin>>ch;
	    if(ch=='y'||ch=='Y') flog=1; 
		else flog=0;
	}
	} 

