for _ in range(int(input())):
	n=int(input())
	a=input()
	b=input()
	ar1=[]
	ar2=[]
	c=0
	for i in range(n):
		ar1.append(int(a[i]))
		ar2.append(int(b[i]))

	for i in range(n):

		if i==0:
			if ar2[i]==1:
				if ar1[i]==0:
					ar1[i]=None
					c+=1
				elif ar1[i+1]==1:
					ar1[i+1]=None
					c+=1
		elif i==n-1:
			if ar2[i]==1:
				if ar1[i]==0:
					ar1[i]=None 
					c+=1
				elif ar1[i-1]==1:
					ar1[i-1]=None
					c+=1
		else:
			if ar2[i]==1:
				if ar1[i]==0:
					ar1[i]=None
					c+=1
				elif ar1[i-1]==1:
					ar1[i-1]=None	
					c+=1
				elif ar1[i+1]==1:
					ar1[i+1]=None
					c+=1
	print(c)
					
			
			
			
			
			
			