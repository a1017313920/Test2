#include <stdio.h>
int besti,bestj;
int maxSubSum(int *a,int left,int right){
    int sum=0,i;
    if(left==right){
        //���ǵݹ���ñ���Ҫ�е���ֵ�����
        sum=(a[left]>0?a[left]:0);
        besti=bestj=left;
    }
    else{
        int center=(left+right)/2;
        int leftSum=maxSubSum(a,left,center);//�������������Ӷκ�
        int lbesti=besti;
        int lbestj=bestj;
        int rightSum=maxSubSum(a,center+1,right);//�������������Ӷκ�
        int rbesti=besti;
        int rbestj=bestj;
        //���ǰ�����ε���������м�ֱ���������չ��
        //���м�������չ������ע�⣬�м�����ĵ�һ����Ȼ�������ڡ�
        int s1=0;int lefts=0;int mbesti=1;
        int i; 
        for(i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>s1){
                mbesti=i;
                s1=lefts;
            }
        }
        //���м�������չ���м����ҵĵ�һ����Ȼ��������
        int s2=0;int rights=0;int mbestj=1;
        for(i=++center;i<=right;i++){
            rights+=a[i];
            if(rights>s2){
                mbestj=i;
                s2=rights;
            }
        }
        sum=s1+s2;//sum�����ǰ���������������Ӷκ�
        besti=mbesti;
        bestj=mbestj;
        //���ǰ�����ε�������
        
        if(sum<=leftSum){
            sum=leftSum;//��ס��leftSum��ʾǰ�����е�����Ӷκ�
            besti=lbesti;
            bestj=lbestj;
        }
        if(sum<=rightSum){
            sum=rightSum;//rightSum��ʾ������е�����ֶκ�
            besti=rbesti;
            bestj=rbestj;
        }
    }
    return sum;
}


int main(int argc, const char * argv[]) {
    int i,n,max;
    int a[100];
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    max=maxSubSum(a, 1, n);
    printf("%d\n",max);
    printf("��%d��%d",besti,bestj);
    return 0;
}
