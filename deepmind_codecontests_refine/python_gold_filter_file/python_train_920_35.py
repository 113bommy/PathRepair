n, x = map(int, input().split())
a = list(map(int, input().split()))

min_list = [[a[i] for i in range(n)] for _ in range(n)]
for i in range(1, n):
	for j in range(n):
		min_list[i][j] = min(min_list[i-1][j], a[(j-i) % n])

ans = float("inf")
for i in range(n):
	ans = min(ans, x * i + sum(min_list[i]))

print(ans)