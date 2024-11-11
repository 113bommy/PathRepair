n, m, h = map(int, input().split())
s = list(map(int, input().split()))
ans = 1
for i in range(sum(s) - 1, sum(s) - s[h - 1], -1):
	ans *= (i - n + 1) / i  
print ((1 - ans) if sum(s) >= n else -1)