n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
x=0
s=0
for i in range(m):
	while s+a[x]<b[i]:
		s+=a[x]
		x+=1	
	print(x+1,b[i]-s)