n,a=map(int,input().split())
l=list(map(int,input().split()))
ans=sum(l)
x=min(a,n-a)
for i in range(1,x):
	if l[a-i-1]+l[a+i-1]==1:
		ans-=1
print(ans)