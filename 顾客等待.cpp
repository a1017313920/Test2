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
    cout<<"输入排队人数"<<endl;
    while(cin>>n)
    {
        cout<<"分别输入"<<n<<"个人每个人的时间"<<endl;
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
        cout<<"输入排队人数"<<endl;
    }
    return 0;
}
