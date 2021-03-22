# include<iostream>
# include<iomanip>
#define M 10               //允许的空闲区表长最大为m
#define N 10               //允许的最大作业数量为n
#define MIN 1              //碎片的最大值
#define SADDRESS 200       //空闲分区初始的起始地址
#define SLENGTH  150000    //空闲分区的初始长度
using namespace std; 
struct used_t{
	float address;       //已分分区起始地址
	float length;        //已分分区长度
	int flag;            //已分配表区登记栏标志，用0表示空栏目
	}used_table[N];
struct free_t{
	float address;       //空闲分区起始地址
	float length;        //空闲分区长度
	int flag;            //空闲分区表登记栏目用0表示空栏目，1表示未分配
}free_table[M];          //空闲分区表
void allocate(char,float);      //分配算法子程序
void reclaim(char);             //回收算法子程序
int main(){
	int i,a;
	float zyl; 
	char zyn;
	//空闲分区表初始化
	free_table[0].address=SADDRESS;      //空闲分区表的起始地址
	free_table[0].length=SLENGTH;        //空闲分区表的长度
       free_table[0].flag=1;                //标志位置1表示未分配
	for(i=1;i<M;i++)
	{	free_table[i].address=0;
		free_table[i].length=0;
		free_table[i].flag=0; }           //0表示空栏目
	//已分分区表初始化
    for(i=0;i<N;i++)
	{	used_table[i].address=0;
		used_table[i].length=0;
		used_table[i].flag=0;}
	while(1){cout<<"请选择功能项："<<endl
			<<"1-分配主存"<<endl
			<<"2-回收主存"<<endl
			<<"3-显示主存"<<endl
			<<"0-退出"<<endl
			<<"选择功能项(0-3):";
		cin>>a;
	switch(a){case 0:           //当选择0时退出程序
			return 0;
		case 1: {          //a=1 分配主存空间
			cout<<"\n请输入作业名zyn和作业所需长度zyl(作业名为一个字符，长度zyl要小于"<<SLENGTH<<"):"<<endl;
			cin>>zyn>>zyl;
			allocate(zyn,zyl);   //为作业zyn分配主存空间
			break;
			}
	case 2:{            // a=2 回收主存空间
			cout<<"\n请输入要回收分区的作业名：";
			cin>>zyn;
			reclaim(zyn);       //回收作业zyn的主存空间
			break;}
	   case 3: {        //a=3 显示主存情况，输出空闲区表和已分配区表
            cout<<"\n输出空闲区表："<<endl
			<<"   起始地址     分区长度     标志"<<endl;
			for(i=0;i<M;i++)
			  if(free_table[i].flag!=0)
cout<<setw(10)<<free_table[i].address<<setw(10)<<free_table[i].length
	<<setw(10)<<free_table[i].flag<<endl;
     cout<<"\n按任意键，输出已分配区表……";
			cin.get();
			cout<<"\n输出已分配区表："<<endl
			<<"   起始地址     分区长度     标志"<<endl;
			for(i=0;i<N;i++){
	if(used_table[i].flag!=0)//输出已分配给作业的表目
				   cout<<setw(10)<<used_table[i].address<<setw(10)<<used_table[i].length
				       <<setw(10)<<(char)used_table[i].flag<<endl; }
		break;}
		default:{ 
			cout<<"\n没有该选项！"<<endl;
			break;
			}}}
  cin.get()}//分配算法子程序
void allocate(char zyn,float zyl)
{       float ad;
	int k=-1;
	int i=0;
	while(i<M&&k==-1)
	{          //找空间大于zyl的最小空闲区登记项k
		if(free_table[i].length>=zyl&&free_table[i].flag==1)
		     k=i;
		 i++;}
	if(k==-1)
	{          //未找到可用空闲区，返回
		cout<<"无可用空闲区！"<<endl;
		return;}
/*找到可用空闲区，开始分配：若空闲区大小与作业要求分配的空间差小于MIN,则将找到的空闲区全部分配给该作业；若空闲区大小与要求分配的空间的差大于minisize,则从空闲区划出一部分分配给作业。*/
   if(free_table[k].length-zyl<=MIN)
   { free_table[k].flag=0;
	 ad=free_table[k].address;        
	 zyl=free_table[k].length;
 	 for(i=k;i<M;i++)
		free_table[i]=free_table[i+1]; }
   else{
     free_table[k].length=free_table[k].length-zyl;
 	 ad=free_table[k].address;
	 free_table[k].address=free_table[k].address+zyl;
	 }
/*修改已分配区表*/
  i=0;
  while(used_table[i].flag!=0&&i<N)   i++;  //找空表目i
     used_table[i].address=ad;
	 used_table[i].length=zyl;
	 used_table[i].flag=zyn;
	 return;}//allocate
//回收作业名为J的作业所占主存空间
void reclaim(char zyn){
	int i,k,j,s,t;
	float S,L;
	s=0;
	while((used_table[s].flag!=zyn||used_table[s].flag==0)&&s<N)
		s++;                //找到作业zyn在以分配表中的表目s
	if(s>=N){
	  cout<<"找不到该作业！"<<endl;return;}
	used_table[s].flag=0;       //修改以分配表表目s标志为为空表目
	S=used_table[s].address;    //取作业zyn在内存中的首地址
	L=used_table[s].length;     //取作业zyn所分配到的内存的长度
	j=-1;
	k=-1;
	i=0;
	//寻找回收分区的上下邻空闲区，上邻表目k，下邻表目j
	while(i<M&&(j==-1||k==-1)){
        if(free_table[i].flag==1){
if(free_table[i].address+free_table[i].length==S) k=i;
			 if(free_table[i].address==S+L) j=i;}
		i++;}
    if(k!=-1){         //有上邻空闲区
	if(j!=-1){      //有下邻空闲区 即有上下邻空闲区，三项合并
  free_table[k].length=free_table[k].length+free_table[j].length+L;
		   free_table[j].flag=0;}
	else          //上邻空闲区，下邻非空闲区，与上邻合并
	free_table[k].length=free_table[k].length+L;}//if
	else {             //k==-1 无上邻空闲区
	if(j!=-1){     //无上邻空闲区，有下邻空闲区，与下邻合并
  free_table[j].address=S;
free_table[j].length=free_table[j].length+L;}
	 else{         //j==-1 上下邻均为非空闲区，回收区域直接填入
   t=0;     //在空闲区表中寻找空栏目
while(free_table[t].flag==1&&t<M) t++;
if(t>=M){       //空闲区表满，回收空间失败，将已分配区表复原
	cout<<"主存空闲表没有空间，回收失败！！"<<endl;
     used_table[s].flag=zyn;
		 return;
			}
	free_table[t].address=S;
		free_table[t].length=L;
		free_table[t].flag=1; }}
	 for(i=0;i<=M-1;i++)
        for(int j=i;j<M;j++)
         if(free_table[i].address>free_table[j].address)
             {
                 free_t temp;
                 temp=free_table[i];
                 free_table[i]=free_table[j];
                 free_table[j]=temp; }}
