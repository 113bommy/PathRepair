def check(k, adj, n):
	a = [0 for i in range(n+1)]
	f = [0 for i in range(n+1)]

	for i in range(n+1):
		arr = adj[i]
		for j in range(len(arr)):
			if arr[j][1] <= k:
				a[i] = 1
				f[arr[j][0]] = 1
	if sum(a) == n and sum(f) == n:
		return True
	return False


def binSearch(adj, n):
	l = 0
	r = 10**9
	ans = -1
	while l<=r:
		mid = (l+r)//2
		if check(mid, adj, n):
			ans = mid
			r = mid - 1
		else:
			l = mid + 1
	return ans

n, m = map(int, input().split())
adj = [[] for i in range(n+1)]
for i in range(m):
	u, v, d = map(int, input().split())
	adj[u].append((v,d))

print(binSearch(adj, n))