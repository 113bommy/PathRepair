def main():
	n,m,k,x,y=map(int,input().split())

	if n==1:
		if k%m==0:
			print (k//m,k//m,k//m)
		else:
			vl=0
			if y<=(k%m):
				vl=k//m+1
			print (k//m+1,k//m,vl)
		return 


	ma=-1*(10**20)
	mi=(10**20)
	track=0
	ans=0
	xloc=0
	yloc=0

	for i in range(1,n+1):
		increment1=2*(n-i)*m		
		increment2=2*(i-1)*m		
		for j in range(1,m+1):
			
			lo=-1		
			hi=10**18		

			
			while hi-lo>1:
				mid=(lo+hi)//2

				times2=(mid//2)

				if(increment2==0):
					times2=0

				times1=mid-times2
				
				if(increment1==0):
					times1=0
					times2=mid

				sumtotal=(i-1)*m+j+increment1*times1+increment2*times2

				if sumtotal<=k:
					lo=mid

				else:
					hi=mid-1

			times2=hi//2

			if increment2==0:
				times2=0

			times1=hi-times2

			if increment1==0:
				times1=0
				times2=hi

			sumtotal=(i-1)*m+j+increment1*times1+increment2*times2

			if sumtotal<=k:
				ans=hi+1

			else:
				ans=hi
			
			#print (i,j,ans,sumtotal,k)
			if(i==x and j==y):
				track=ans
			if ans>ma:
				ma=ans
			if ans<mi:
				mi=ans

	print (ma,mi,track)
	return

main()