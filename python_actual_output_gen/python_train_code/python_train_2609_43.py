n, k, *h = map(int, open(0).read().split())
h.sort()
ans = 0
for i in range(n-k+1):
	ans = min(ans, h[i+k-1]-h[i])
print(ans)