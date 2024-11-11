n,m=[int(i) for i in input().split()]
if n==1:
	ans=1
if m-1>n-m-1:
	ans=m-1
else:
	ans=m+1
print(ans)
