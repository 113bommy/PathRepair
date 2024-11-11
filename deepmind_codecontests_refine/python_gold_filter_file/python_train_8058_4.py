n,m=map(int,input().split())
l=list(map(int,input().split()))
l1=l[::-1]
sl=0
setlen=[0]*(n+1)
setindex=[0]*100001
i=n
while(i>0):
	if setindex[l1[n-i]]!=1:
		sl+=1
		setindex[l1[n-i]]=1
	setlen[i]=sl
	i-=1

for i in range(m):
	a=int(input())
	print(setlen[a])

