#include <iostream>
#include <algorithm>
//#include <cstdlib>
using namespace std;
double avg(double a[],int n){
double sum=0;
for(int i=0;i<n;i++){
    sum+=a[i]*(n-i);
}
return sum/n;
}
int main()
{
 
 
    double time[100];
    int n;
    cout<<"�����Ŷ�����"<<endl;
    while(cin>>n)
    {
        cout<<"�ֱ�����"<<n<<"����ÿ���˵�ʱ��"<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>time[i];
        }
        sort(time,time+n);
        //sort(time,n);
        for(int i=0; i<n; i++)
            cout<<time[i]<<" ";
        cout<<endl;
        double ans=avg(time,n);
        cout<<ans;
        cout<<"�����Ŷ�����"<<endl;
    }
    return 0;
}
