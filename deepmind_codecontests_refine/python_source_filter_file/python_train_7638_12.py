n,m,k = list(map(int,input().split()))
arr = []
for i in range(n):
	arr.append(list(map(int,input().split())))
f = arr[0][0]%k
g = 0
for i in range(n):
	for j in range(m):
		e = arr[i][j]%k
		if e==f:
			pass
		else:
			g = 1
			break
if g==1:
	print(-1)
else:
	ans = []
	all_val = []
	for i in range(n):
		all_val+=arr[i]
	all_val = list(set(all_val))
	for i in all_val:
		cnt = 0
		for j in range(n):
			for k in range(m):
				cnt+=abs(i-arr[j][k])
		ans.append(cnt)
	print(min(ans)//k)