n,m = map(int,input().split())
k = m//n
ans = 1
i = 1
while i**2 <= m:
	if m%i==0:
		j = m/i
		if j <= k:
			print(j);exit()
		if i <= k:
			ans = max(ans,i)
	i += 1
print(ans) 
