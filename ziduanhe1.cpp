#include <stdio.h>
int b[3]={0,0,0};
int * maxSubSum(int a[],int left,int right){
    int sum=0,i;
    if(left==right){
        //这是递归调用必须要有的终值情况。
        b[0]=(a[left]>0?a[left]:0);
        b[1]=b[2]=left;
    }
    else{
        int center=(left+right)/2;
        maxSubSum(a,left,center);//求出左序列最大子段和
        int leftSum=b[0];
        int lbesti=b[1];
        int lbestj=b[2];
        maxSubSum(a,center+1,right);//求出右序列最大子段和
        int rightSum=b[0];
        int rbesti=b[1];
        int rbestj=b[2];
        //求跨前后两段的情况，从中间分别向两端扩展。
        //从中间向左扩展。这里注意，中间往左的第一个必然包含在内。
        int ls=0;int lefts=0;int mbesti=1;
        for(int i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>ls){
                mbesti=i;
                ls=lefts;
            }
        }
        //从中间向右扩展。中间往右的第一个必然包含在内
        int rs=0;int rights=0;int mbestj=1;
        for(i=++center;i<=right;i++){
            rights+=a[i];
            if(rights>rs){
                mbestj=i;
                rs=rights;
            }
        }
        b[0]=ls+rs;//sum保存跨前后两段情况的最大子段和
        b[1]=mbesti;
        b[2]=mbestj;
        //求跨前后两段的情况完成
        
        if(b[0]<=leftSum){
            b[0]=leftSum;//记住，leftSum表示前段序列的最大子段和
            b[1]=lbesti;
            b[2]=lbestj;
        }
        if(b[0]<=rightSum){
            b[0]=rightSum;//rightSum表示后段序列的最大字段和
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
    printf("从%d到%d",b[1],b[2]);
    return 0;
}
