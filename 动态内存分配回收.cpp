# include<iostream>
# include<iomanip>
#define M 10               //����Ŀ����������Ϊm
#define N 10               //����������ҵ����Ϊn
#define MIN 1              //��Ƭ�����ֵ
#define SADDRESS 200       //���з�����ʼ����ʼ��ַ
#define SLENGTH  150000    //���з����ĳ�ʼ����
using namespace std; 
struct used_t{
	float address;       //�ѷַ�����ʼ��ַ
	float length;        //�ѷַ�������
	int flag;            //�ѷ�������Ǽ�����־����0��ʾ����Ŀ
	}used_table[N];
struct free_t{
	float address;       //���з�����ʼ��ַ
	float length;        //���з�������
	int flag;            //���з�����Ǽ���Ŀ��0��ʾ����Ŀ��1��ʾδ����
}free_table[M];          //���з�����
void allocate(char,float);      //�����㷨�ӳ���
void reclaim(char);             //�����㷨�ӳ���
int main(){
	int i,a;
	float zyl; 
	char zyn;
	//���з������ʼ��
	free_table[0].address=SADDRESS;      //���з��������ʼ��ַ
	free_table[0].length=SLENGTH;        //���з�����ĳ���
       free_table[0].flag=1;                //��־λ��1��ʾδ����
	for(i=1;i<M;i++)
	{	free_table[i].address=0;
		free_table[i].length=0;
		free_table[i].flag=0; }           //0��ʾ����Ŀ
	//�ѷַ������ʼ��
    for(i=0;i<N;i++)
	{	used_table[i].address=0;
		used_table[i].length=0;
		used_table[i].flag=0;}
	while(1){cout<<"��ѡ�����"<<endl
			<<"1-��������"<<endl
			<<"2-��������"<<endl
			<<"3-��ʾ����"<<endl
			<<"0-�˳�"<<endl
			<<"ѡ������(0-3):";
		cin>>a;
	switch(a){case 0:           //��ѡ��0ʱ�˳�����
			return 0;
		case 1: {          //a=1 ��������ռ�
			cout<<"\n��������ҵ��zyn����ҵ���賤��zyl(��ҵ��Ϊһ���ַ�������zylҪС��"<<SLENGTH<<"):"<<endl;
			cin>>zyn>>zyl;
			allocate(zyn,zyl);   //Ϊ��ҵzyn��������ռ�
			break;
			}
	case 2:{            // a=2 ��������ռ�
			cout<<"\n������Ҫ���շ�������ҵ����";
			cin>>zyn;
			reclaim(zyn);       //������ҵzyn������ռ�
			break;}
	   case 3: {        //a=3 ��ʾ����������������������ѷ�������
            cout<<"\n�����������"<<endl
			<<"   ��ʼ��ַ     ��������     ��־"<<endl;
			for(i=0;i<M;i++)
			  if(free_table[i].flag!=0)
cout<<setw(10)<<free_table[i].address<<setw(10)<<free_table[i].length
	<<setw(10)<<free_table[i].flag<<endl;
     cout<<"\n�������������ѷ���������";
			cin.get();
			cout<<"\n����ѷ�������"<<endl
			<<"   ��ʼ��ַ     ��������     ��־"<<endl;
			for(i=0;i<N;i++){
	if(used_table[i].flag!=0)//����ѷ������ҵ�ı�Ŀ
				   cout<<setw(10)<<used_table[i].address<<setw(10)<<used_table[i].length
				       <<setw(10)<<(char)used_table[i].flag<<endl; }
		break;}
		default:{ 
			cout<<"\nû�и�ѡ�"<<endl;
			break;
			}}}
  cin.get()}//�����㷨�ӳ���
void allocate(char zyn,float zyl)
{       float ad;
	int k=-1;
	int i=0;
	while(i<M&&k==-1)
	{          //�ҿռ����zyl����С�������Ǽ���k
		if(free_table[i].length>=zyl&&free_table[i].flag==1)
		     k=i;
		 i++;}
	if(k==-1)
	{          //δ�ҵ����ÿ�����������
		cout<<"�޿��ÿ�������"<<endl;
		return;}
/*�ҵ����ÿ���������ʼ���䣺����������С����ҵҪ�����Ŀռ��С��MIN,���ҵ��Ŀ�����ȫ�����������ҵ������������С��Ҫ�����Ŀռ�Ĳ����minisize,��ӿ���������һ���ַ������ҵ��*/
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
/*�޸��ѷ�������*/
  i=0;
  while(used_table[i].flag!=0&&i<N)   i++;  //�ҿձ�Ŀi
     used_table[i].address=ad;
	 used_table[i].length=zyl;
	 used_table[i].flag=zyn;
	 return;}//allocate
//������ҵ��ΪJ����ҵ��ռ����ռ�
void reclaim(char zyn){
	int i,k,j,s,t;
	float S,L;
	s=0;
	while((used_table[s].flag!=zyn||used_table[s].flag==0)&&s<N)
		s++;                //�ҵ���ҵzyn���Է�����еı�Ŀs
	if(s>=N){
	  cout<<"�Ҳ�������ҵ��"<<endl;return;}
	used_table[s].flag=0;       //�޸��Է�����Ŀs��־ΪΪ�ձ�Ŀ
	S=used_table[s].address;    //ȡ��ҵzyn���ڴ��е��׵�ַ
	L=used_table[s].length;     //ȡ��ҵzyn�����䵽���ڴ�ĳ���
	j=-1;
	k=-1;
	i=0;
	//Ѱ�һ��շ����������ڿ����������ڱ�Ŀk�����ڱ�Ŀj
	while(i<M&&(j==-1||k==-1)){
        if(free_table[i].flag==1){
if(free_table[i].address+free_table[i].length==S) k=i;
			 if(free_table[i].address==S+L) j=i;}
		i++;}
    if(k!=-1){         //�����ڿ�����
	if(j!=-1){      //�����ڿ����� ���������ڿ�����������ϲ�
  free_table[k].length=free_table[k].length+free_table[j].length+L;
		   free_table[j].flag=0;}
	else          //���ڿ����������ڷǿ������������ںϲ�
	free_table[k].length=free_table[k].length+L;}//if
	else {             //k==-1 �����ڿ�����
	if(j!=-1){     //�����ڿ������������ڿ������������ںϲ�
  free_table[j].address=S;
free_table[j].length=free_table[j].length+L;}
	 else{         //j==-1 �����ھ�Ϊ�ǿ���������������ֱ������
   t=0;     //�ڿ���������Ѱ�ҿ���Ŀ
while(free_table[t].flag==1&&t<M) t++;
if(t>=M){       //���������������տռ�ʧ�ܣ����ѷ�������ԭ
	cout<<"������б�û�пռ䣬����ʧ�ܣ���"<<endl;
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
