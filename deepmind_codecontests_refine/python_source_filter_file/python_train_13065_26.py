n,m=map(int,input().split())
cnt=0
for i in range(n):
	a=list(map(int,input().split()))
	for i in range(m):
		if a[i]==1 or a[i+m]==1:
			cnt+=1
print(cnt)