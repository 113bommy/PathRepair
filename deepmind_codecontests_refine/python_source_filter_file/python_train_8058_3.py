n,m=map(int,input().split())
a=list(map(int,input().split()))
k=[0]*n
d={}
c=0
for i in range(n-1,0,-1):
	if a[i] not in d:
		c=c+1
		d[a[i]]=1
	k[i]=c

#print(*k)
for i in range(0,m):
	k1=int(input())
	print(k[k1-1])

	