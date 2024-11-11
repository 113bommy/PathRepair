def minimumTime(n, x, c):
	c_sorted = sorted(c)
	ans = 0
	for i in range(n):
		ans += c[i] - max(1, x - i)
	return ans

n, x = map(int, input().split())
c = list(map(int, input().split()))

print(minimumTime(n, x, c))