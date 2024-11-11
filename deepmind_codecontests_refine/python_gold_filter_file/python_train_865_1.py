n,m,c=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
sum=0

for i in range(n):

	if i<m:
		sum=(sum+b[i])%c

	if i>=n-m+1:
		sum=(c+sum-b[i-(n-m+1)])%c

	a[i]=(a[i]+sum)%c

print(' '.join(map(str,a)))
