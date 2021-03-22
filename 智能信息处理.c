/*模糊ISODATA聚类分析的C语言程序*/
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
/* N-样本个数，M-样本特性指标个数，C-分类类别个数*/ 
int N,M,C;

/*分配内存空间函数*/ 
double * * mat_alloc(int nrows , int ncols)
{
	double **mat;
	int i;
	mat= (double **)malloc(sizeof(double *)*nrows);
	for(i=0;i<nrows;i++)
	{
		mat[i]=(double *) malloc(sizeof(double)*ncols);
	}
	return (mat);
}
/*计算矩阵X的第k行和矩阵V的第i行距离的函数*/
double compute_dis(double **mat1, int k_row, double **mat2, int i_row, int n_col, int d)
{
	double x, max;
	int j;
	
	switch(d)
	{
	case 1:
			max=0;
			for(j=0;j<n_col; j++)
			{
				if((x=fabs(mat1[k_row][j]-mat2[i_row][j]))>max) max=x;
			}
			return max;
	
	case 2:
			max=0;
			for(j=0;j<n_col;j++)
			{
				max += pow((mat1[k_row][j]-mat2[i_row][j]),2);
			}
			
			return sqrt(max);
case 3:
			max=0;
			for(j=0;j<n_col;j++)
			{
				max += fabs(mat1[k_row][j]-mat2[i_row][j]);
			}
			return max;
	}
}

main( )
{
	double **X,  **R, **V, **R1, **n_R;
	double **newSample;
	float b;
	int i,j,k;
	double E,Q;
	int D;
	double n_sum, m_sum, distance;
	double ki_dis, kj_sum;
	double F, H;
	int n_new, i_min;
	double min;
	double max, x; 
	int param;
	printf("please input N, M, C：");
	scanf("%d%d%d", &N, &M, &C) ;
	printf("\n");
	
	printf("please input matrix X:\n");
	
	/*输入矩阵X, N个样本的M个特性指标*/
	X=mat_alloc(N,M);
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
		{
			scanf("%f", &b);
			X[i][j]=(double)b;
		} 
	printf("\n");
	
loop2: printf("please input matrix R：\n");
	/*输入初始分类矩阵R*/
	R = mat_alloc(C,N);
	
	for(i=0;i<C;i++)
		for(j=0;j<N;j++)
		{
			scanf("%f",&b);
			R[i][j] = (double)b;
		}
	
	printf("\n");
	printf("please input the value E,Q: \n");
	
	/*输入阈值 E， Q*/
loop1: scanf("%f", &b);
		E = (double)b;
		scanf("%f", &b);
		Q = (double)b;
		
		printf("\n");
		/*输入D, "1"：采用Chebyshev 距离， "3": Hamming距离；  "2"：Euclid 距离 */
		printf("please input D. 1:Chebyshev;  2: Euclid;  3: Hamming;\n");
		scanf("%d", &D);
		printf("\n");
	
	do
	{
		/*计算聚类中心矩阵*/
		V = mat_alloc(C,M);
		
		for(i=0; i<C; i++)
			for(j=0; j<M; j++) 
			{
				n_sum = 0;
				m_sum = 0;
				for(k=0; k<N; k++)
				{
					n_sum += pow(R[i][k], Q) * X[k][j];
					m_sum += pow(R[i][k], Q);
				}
				
			
				V[i][j] = n_sum/m_sum;
				
				
			}
			
			
		/*修正模糊分类矩阵R */	
		
		R1 = mat_alloc(C,N);
		for(i=0; i<C; i++)
			for(k=0; k<N; k++)
			{
				kj_sum = 0;
				
				for(j=0; j<C; j++)
				{
					printf("D%d%d=%20.12e\n", k, j, compute_dis(X,k,V,j,M,D));
					
					if(j != i)
						kj_sum += pow((compute_dis(X,k,V,i,M,D)/compute_dis(X,k,V,j,M,D)), (2/(Q-1)));
				}
				
				R1[i][k] = pow((kj_sum+1), (double)(-1));
				
			}
			
		/* 比较R和R*的精度 */
		
		max = 0;
		for(i=0; i<C; i++)
			for(j=0;j<N;j++)
			{
				printf("|R1[%d][%d] - R[%d][%d]| = %20.12e\n", i,j,i,j,fabs(R1[i][j]-R[i][j]));
				
if(fabs(R1[i][j]-R[i][j])> max )  max = fabs(R1[i][j] - R[i][j]);
			}
			
		getch();
		printf("max = %20.12e\n", max);
		if(max > E)
		
		{
			for(i=0;i<C;i++)
				for(j=0;j<N;j++)
					R[i][j] = R1[i][j];
					
			free(V);
		}
			
	} while(max>E);  /*  end  do-while( )循环*/
		
   /*输出模糊分类矩阵R1和聚类中心矩阵 V */ 
   		printf("please output the matrix R1: ");
   
   		for(i=0;i<C;i++)
   			for(j=0;j<N;j++)
   			{
   				printf("%20.12e",R1[i][j]);
   				
   				printf("\n");
		   	
			}
		
		printf("\n");
		
		printf("please output the matrix V: \n");
		
		for(i=0; i<C; i++)
		{
			for(j=0; j<M;j++)
				
				printf("%8.4f", V[i][j]);
				
				printf("\n");
		}
		
		printf("\n");
		
	/* n_R 矩阵存放矩阵R的类别，并且输出各样本的类别*/
	
		n_R = mat_alloc(C,N);
		for(j=0; j<N; j++)
		{
			max = R1[0][j];
			n_R[0][j]=1;
			for(i=1; i<C;i++)
			{
				if(R1[i][j]>max)
				{
					max = R1[i][j];
					n_R[i][j]=1;
					
					if(i == 1) 	{ n_R[0][j] = 0;}
				}
			
				else n_R[i][j]=0;
			}
		} 
		
	/*输出类别*/
	
		for(i=0;i<C;i++)
		{
			printf("These samples belog to class %d:\n", i);
			for(j=0;j<N;j++)
				if( n_R[i][j] == 1) printf("%5d", j+1);
			
			printf("\n");
			
		}
		
		/*计算聚类效果指标F(R)和H(R)并且输出*/
	
		F=0; H =0;
		for(i=0;i<C;i++)
			for(j=0;j<N;j++)
			{
				F += pow(R1[i][j], 2) ;
				H += R1[i][j]*log(R1[i][j]);
			}
			
		F = F/N;
		H = -H/N;
		printf("F(R)=%e, F(R)=%8.5f\n", F, F);
		
		printf("H(R)=%e, H(R)=%8.5f\n", H, H);
			
		/*需要调整参数E，Q，D的值吗？ 如果要调整请输入1，否则输入0*/
			
		printf("More adjust param  E, Q, D?  yes: input 1, no:input 0  : \n" );
		scanf("%d", &param);
		
		if(param == 1)
		{
			free(R1);
			free(n_R);
			goto  loop1;
		}
		
		/*调整分类矩阵R？*/
	
printf("More adjust matrix R?   yes: input 1;  no:input 0 :\n")	;
	scanf("%d", &param);
		
		if(param == 1)
		{
			free(R);
			free(R1);
			free(n_R);
			goto loop2;
		}
		
		/*输入新样本？ 如果输入新样本，请输入1，否则输入0 */
		printf("input new sample?  yes:input 1;  no:input 0   :");
		scanf("%d", &param);
		
		printf("\n");
		if(param == 1)
		{
			printf("input the number of the new samples: \n");
			scanf("%d", &n_new);
			printf("\n");
			
			newSample = mat_alloc(n_new, M);
			printf("input the new samples: \n");
			for(i=0; i<n_new; i++)
				for(j=0;j<M;j++)
				{
					scanf("%f", &b);
					newSample[i][j] = (double)b;
					
				}
			for(i=0; i<n_new; i++)
			{
				min = compute_dis(newSample,0,V,0,M,D);
				i_min = 0;
				for(j=1;j<C;j++)
				if(min > compute_dis(newSample,i,V,j,M,D))  i_min = j;
				
				printf("the new sample belong to class %d. \n ", i_min+1);
			}
		}    /*end if*/
		
		getch();
		free(X);
		free(R);
		free(R1);
		free(V);
		free(n_R);
		
}/*end main*/

