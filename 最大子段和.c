#include <stdio.h>
int besti,bestj;
int maxSubSum(int *a,int left,int right){
    int sum=0,i;
    if(left==right){
        //这是递归调用必须要有的终值情况。
        sum=(a[left]>0?a[left]:0);
        besti=bestj=left;
    }
    else{
        int center=(left+right)/2;
        int leftSum=maxSubSum(a,left,center);//求出左序列最大子段和
        int lbesti=besti;
        int lbestj=bestj;
        int rightSum=maxSubSum(a,center+1,right);//求出右序列最大子段和
        int rbesti=besti;
        int rbestj=bestj;
        //求跨前后两段的情况，从中间分别向两端扩展。
        //从中间向左扩展。这里注意，中间往左的第一个必然包含在内。
        int s1=0;int lefts=0;int mbesti=1;
        int i; 
        for(i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>s1){
                mbesti=i;
                s1=lefts;
            }
        }
        //从中间向右扩展。中间往右的第一个必然包含在内
        int s2=0;int rights=0;int mbestj=1;
        for(i=++center;i<=right;i++){
            rights+=a[i];
            if(rights>s2){
                mbestj=i;
                s2=rights;
            }
        }
        sum=s1+s2;//sum保存跨前后两段情况的最大子段和
        besti=mbesti;
        bestj=mbestj;
        //求跨前后两段的情况完成
        
        if(sum<=leftSum){
            sum=leftSum;//记住，leftSum表示前段序列的最大子段和
            besti=lbesti;
            bestj=lbestj;
        }
        if(sum<=rightSum){
            sum=rightSum;//rightSum表示后段序列的最大字段和
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
    printf("从%d到%d",besti,bestj);
    return 0;
}
