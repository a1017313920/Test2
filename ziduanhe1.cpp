#include <stdio.h>
int b[3]={0,0,0};
int * maxSubSum(int a[],int left,int right){
    int sum=0,i;
    if(left==right){
        //���ǵݹ���ñ���Ҫ�е���ֵ�����
        b[0]=(a[left]>0?a[left]:0);
        b[1]=b[2]=left;
    }
    else{
        int center=(left+right)/2;
        maxSubSum(a,left,center);//�������������Ӷκ�
        int leftSum=b[0];
        int lbesti=b[1];
        int lbestj=b[2];
        maxSubSum(a,center+1,right);//�������������Ӷκ�
        int rightSum=b[0];
        int rbesti=b[1];
        int rbestj=b[2];
        //���ǰ�����ε���������м�ֱ���������չ��
        //���м�������չ������ע�⣬�м�����ĵ�һ����Ȼ�������ڡ�
        int ls=0;int lefts=0;int mbesti=1;
        for(int i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>ls){
                mbesti=i;
                ls=lefts;
            }
        }
        //���м�������չ���м����ҵĵ�һ����Ȼ��������
        int rs=0;int rights=0;int mbestj=1;
        for(i=++center;i<=right;i++){
            rights+=a[i];
            if(rights>rs){
                mbestj=i;
                rs=rights;
            }
        }
        b[0]=ls+rs;//sum�����ǰ���������������Ӷκ�
        b[1]=mbesti;
        b[2]=mbestj;
        //���ǰ�����ε�������
        
        if(b[0]<=leftSum){
            b[0]=leftSum;//��ס��leftSum��ʾǰ�����е�����Ӷκ�
            b[1]=lbesti;
            b[2]=lbestj;
        }
        if(b[0]<=rightSum){
            b[0]=rightSum;//rightSum��ʾ������е�����ֶκ�
            b[1]=rbesti;
            b[2]=rbestj;
        }
    }
    return b;
}


int main(int argc, const char * argv[]) {
    int n;
    int a[100];
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    maxSubSum(a, 1, n);
    printf("%d\n",b[0]);
    printf("��%d��%d",b[1],b[2]);
    return 0;
}
