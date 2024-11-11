n,k=map(int,input().split())
a=[0]+[int(input())-k for i in range(n)]
for i in range(1,n+1):
	a[i]+=a[i-1]
b=sorted(a)+[-2e9-1]
c,d=0,dict()
for i in range(n+1):
	if b[i]!=b[i-1]:
		c+=1
		d[b[i]]=c
bit=[0]*(n+5)
def sum(i):
	res=0
	while i>0:
		res+=bit[i]
		i-=i&-i
	return res
def add(i):
	while i<=c:
		bit[i]+=1
		i+=i&-i
ans=0
for i in range(n+1):
	ans+=sum(d[a[i]])
	add(d[a[i]])
print(ans)