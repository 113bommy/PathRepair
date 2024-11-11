import math
def primenum(x):
	count=0
	for i in range(2,int(math.floor(math.sqrt(x)))+1):
		if(x%i==0):
			count=count+1
	if(count==0):
		return True
	else:
		return False
n,k=map(int,input().split())
l=[]
m=[]
c=0
if(k>n or k==0):
	print('NO')
else:
	for i in range(2,n+1):
		if (primenum(i)==True):
			l.append(i)
	for i in range(len(l)-1):
		m.append(l[i]+l[i+1]+1)
	for i in range(len(m)):
		if m[i] in l:
			c=c+1
	if(c>=k):
		print('YES')
	else:
		print('NO')
