n = int(input())
a = list(map(int, input().split()))

dp1 = [x for x in a]
dp2 = [0 for _ in range(1<<n)]

for j in range(n+1):
	for i in range(1<<n):
		if i & (1<<j):
			if dp1[i & ~(1<<j)] >= dp1[i]:
				if dp2[i & ~(1<<j)] >= dp1[i]:
					dp2[i] = dp2[i & ~(1<<j)]
				else:
					dp2[i] = dp1[i]
				dp1[i] = dp1[i & ~(1<<j)]
			else:
				if dp1[i & ~(1<<j)] >= dp2[i]:
					dp2[i] = dp1[i & ~(1<<j)]

ans = 0
for i in range(1, 1<<n):
	ans = max(ans, dp1[i]+dp2[i])
	print(ans)