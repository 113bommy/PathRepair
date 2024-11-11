n,k,m,d = [int(x) for x in input().split()]
ans = 0
for t in range(1,d+1):
	R = n // ((t-1)*k + 1)
	L = n // (t*k)
	if L <= R:
		if L <= m <= R:
			ans = max(ans,m*t)
		elif R <= m:
			ans = max(ans,R*t)

print(ans)
