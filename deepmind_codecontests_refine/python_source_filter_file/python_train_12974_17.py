DAY = 86400

n, t = map(int, input().split())
A = list(map(int, input().split()))

for i in range(n):
	t -= min(t, DAY - A[i])
	if t == 0:
		print(i + 1)
