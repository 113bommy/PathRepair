k,n=map(int,input().split())
a=list(map(int,input().split()))
a+=[k+a[0]]
s=0
for i in range(n):
	s=max(s,a[i+1]-a[i])
print(s)