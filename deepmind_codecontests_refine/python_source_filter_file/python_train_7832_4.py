t=int(input())
for t1 in range(0,t):
	n=int(input())
	a=list(map(int,input().split()))
	ans=[]
	ans.append(a[0])
	
	for i in range(2,n-1):
		if (abs(a[i]-a[i-1])+abs(a[i+1]-a[i])) != abs(a[i-1]-a[i+1]):
			ans.append(a[i])
	if(a[n-1]!=ans[-1]):
		ans.append(a[n-1])
	print(len(ans))
	print(*ans)
