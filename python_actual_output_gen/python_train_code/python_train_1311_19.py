n,k=map(int,input().split())
count=0
if k<=n:
	count+=1
for i in range(2,n+1):
	if k%i==0 and k//i<=k:
		count+=1
print(count)