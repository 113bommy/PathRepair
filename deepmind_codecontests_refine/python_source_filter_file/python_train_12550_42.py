n,c=map(int,input().split())
a=list(map(int,input().split()))
count=0
for i in range(n-1):
	if (a[i+1]-a[i])<=c:
		count+=1
	if (a[i+1]-a[i])>c:
		count=1
print(count)			