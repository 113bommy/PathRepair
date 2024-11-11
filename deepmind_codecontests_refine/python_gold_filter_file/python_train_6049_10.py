import math
n,a,b=map(int,input().split())
a1=list(map(int,input().split()))
c=0
k=0
for j in range(math.ceil(n/2)):
	if(a1[j]==2 and a1[-(j+1)]!=2):
		a1[j]=a1[-(j+1)]
		if(a1[j]==0):
			k=k+a
		else:
			k=k+b
	if(a1[j]!=2 and a1[-(j+1)]==2):
		a1[-(j+1)]=a1[j]
		if(a1[j]==0):
			k=k+a
		else:
			k=k+b
	if(a1[j]==2 and a1[-(j+1)]==2):
		# if(n%2==0):
		# 	k=k+2*min(a,b)
		if(n%2!=0 and j==((math.ceil(n/2))-1)):
			k=k+min(a,b)
		else:
			k=k+2*min(a,b)
	if(a1[j]!=a1[-(j+1)]):
		c=1
		break
if(c==1):
	print(-1)
else:
	print(k)