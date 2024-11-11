t=int(input())

for i in range(t):
	n=int(input())
	a=list(map(int,input().split()))
	d={}
	ans=[]
	for j in range(n):
		if a[j] not in d:
			d[a[j]]=j
		else:
			ans.append(j-d[a[j]]+1)
			a[a[j]]=j
		# print(ans,d)
	if len(ans)==0:
		print(-1)
	else:
		print(min(ans))
