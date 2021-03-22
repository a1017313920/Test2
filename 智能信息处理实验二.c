#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
/*�����ڴ�ռ亯��*/
double **mat_alloc(int nrows, int ncols)
{
	double **mat;
	int i;
	mat=(double **)malloc(sizeof(double *)*nrows);
	for(i=0;i<nrows;i++)
	{
		mat[i]=(double*)malloc(sizeof(double)*ncols);
	}
	
	return (mat);
}

main( )
{
	double  **C,  *A,  *a,  **F,  **V,  **R,  *B,  *D,   **R1;
	double  A_max,  A_min, d,  F_imax,  F_imin,  a_avg,  V_jsum;
	
	float  b;
	int  L,  M,  N,  p;
	
	int  i,  j,  j_max,  j_min;
	
	double  max,  min;
	
	/*����ר������L�����۷�������M�����ظ���N*/
	printf("������ר������L��");
	scanf("%d",&L);
	printf("\n");
	printf("���������۷�������M��");
	scanf("%d", &M);
	printf("\n");
	
	printf("���������ظ���N��");
	scanf("%d",&N);
	printf("\n");
		 	
  	/*ΪN������ָ�꣬�������ָ���ȨֵA*/
  	
	printf("������Ȩֵ����A[N]:\n");
	a=(double *)malloc(N*sizeof(double));
	for(i=0;i<N;i++)
	{
		scanf("%f",&b);
		a[i]=(double)b; 
	}
	
	/*����p*/
	
	printf("����p�������������־��߷���ѡ�񷽰�:");
	scanf("%d",&p);
	printf("\n");
		
	switch(p)
	{
		case 1:   /*����ָ��ֵ����F*/
		printf("������ָ��ֵ����F��\n"); 
		F=mat_alloc(N,M);
		
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
			{
				scanf("%f", &b);
				F[i][j]=(double)b;
			} 
		printf("\n");
				
		/*�������ƫ�����V*/
		V=mat_alloc(N,M);
		B=(double *)malloc(M*sizeof(double));
		
		for(i=0;i<N;i++)
		{
			F_imax = F[i][0];
			F_imin = F[i][0];
			
			for(j=1;j<M;j++)
			{
				if(F[i][j]>F_imax)  F_imax = F[i][j];
				if(F[i][j]<F_imin)  F_imin = F[i][j];
			}
			
			B[i]=F_imin;
			for(j=0;j<M;j++)
			{
				V[i][j] = fabs(B[i]-F[i][j])/(F_imax-F_imin);
			}
			
		} 
		
		printf("���V0:\n");
		for(i=0;i<N;i++)
		{
			printf("%7.2f",B[i]);
			if(i%5 == 4) printf("\n");
		} 
		/*����������ƫ��ģ������V*/
		
		getch();
		
		printf("����������ƫ��ģ������V ��\n");
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
				printf("%9.2f", V[i][j]);
			printf("\n");
		} 
		printf("\n");
		
		getch();
		
		/*�������ƫ�����*/
		
		D=(double *)malloc(M*sizeof(double)) ;
		
		/*����Ȩֵa��ƽ��ֵ*/
		
		a_avg = 0;
		for(i=0;i<N;i++)
			a_avg += a[i];
		
		a_avg/=N;
		
		for(j=0;j<M;j++)
		{
			V_jsum=0;
			
			for(i=0;i<N;i++)
			{
				V_jsum += pow((a[i]*V[i][j]),2); 
			}
			
			D[j] = sqrt(V_jsum)/a_avg;
		}
		
		break;
		
		case 2:       /*����ָ��ֵ����F*/
		 
		 	printf("������ָ��ֵ����F��\n");
		 	F=mat_alloc(N,M);
		 	
		 	/*R1 =mat_alloc(N,M);*/
		 	
		 	for(i=0;i<N;i++)
		 		for(j=0;j<M;j++)
		 		{
		 			scanf("%f", &b);
		 			F[i][j]=(double)b;
		 		}
		 		
	 		printf("\n");
 		
 		printf("�������F:\n");
		for(i=0;i<N;i++) 
		{
			for(j=0;j<M;j++)
				printf("%7.2f",F[i][j]);
			printf("\n");
		}
		printf("\n");
		
		getch( );
		
		/*����ģ�����۾���R*/
		
		R=mat_alloc(N,M) ;
		for(i=0;i<N;i++)
		{
			F_imax = F[i][0];
			F_imin = F[i][0];
			
			for(j=0;j<M;j++)
			{
				if(F[i][j]>F_imax) F_imax = F[i][j];
				if(F[i][j]<F_imin) F_imin = F[i][j];
			}
		
		  	d=(F_imax -F_imin)/(1-0.1);
		  	for(j=0;j<M;j++)
		  	{
	  			R[i][j] = 0.1 + (F_imax - F[i][j])/d;
	  		}
					
		}
		
			break;
		
		case 3:
		
			/*���붨��ָ������ģ������R*/
		printf("�����붨��ָ��������ģ������R��\n");
		
		R = mat_alloc(N,M);
		for(i=0; i<N; i++)
			for(j=0;j<M;j++)
			{
				scanf("%f",b);
				R[i][j] = (double)b;
			}
			
			printf("\n");
		
	}/*end switch*/	
 	  	
	if((p==2)||(p==3))
	{
		printf("�������R��\n");
		for(i=0;i<N;i++)
		{
			for(j=0;j<M;j++)
				printf("%7.2f",R[i][j]);
			printf("\n");
		}
		
printf("\n");
		
		getch( );
				
		R1=mat_alloc(N,M);
		
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				R1[i][j]=a[i]*R[i][j];
		printf("�������R1��\n");
		
		for(i=0;i<N;i++){
			for(j=0;j<M;j++)
				printf("%7.2f",R1[i][j]);
			
			printf("\n");
				
		}
		printf("\n");
		
		getch();
		
		B=(double *)malloc(M*sizeof(double));
		
		for(j=0;j<M;j++)
			{
				B[j]=0;
				for(i=0;i<N;i++)
					B[j] += R1[i][j];
			}
			
	printf("�������B��\n");
	
		max=B[0];
		j_max =0;
		for(j=0;j<M;j++)
		{
			printf("%7.2f",B[j]);
			
			if(B[j]>max)
			{
				max= B[j];
				j_max = j;
			}
		}
		printf("\n");
		printf("B the best project is %d project \n", j_max+1);
		getch();
	}/*end if*/
	else
	{
		/*���D�Լ����ŷ���*/
		printf("���D[M]:\n");
		min = D[0];
		j_min = 0;
		for(j=0;j<M;j++)
		{
			printf("%7.3f",D[j]);
			if(D[j]<min)
			{
				min = D[j];
				j_min=j;
			}
		} 
		printf("\n");
		printf("���ŷ����Ƿ��� %d \n",j_min+1);
		getch();
	}/*end else*/
	free(a);
	free(B);
	free(R);
	free(R1);
	
	free(F);
	free(D);	
}/*end main*/

