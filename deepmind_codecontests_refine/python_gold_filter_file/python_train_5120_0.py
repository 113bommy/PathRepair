import sys
input = sys.stdin.readline

n, r = map(int, input().split())
l = []
for _ in range(n):
	l.append(list(map(int, input().split())))
p = 0
ans = 0
while (p < n):
	if l[p][0] <= r and l[p][1] >= 0:
		r += l[p][1]
		l = l[:p] + l[p + 1:]
		p = 0
		n -= 1
		ans += 1
	else:
		p += 1
if l == []:
	print(ans)
	exit(0)
q = len(l)
for i in range(q):
	l[i][0] = max(l[i][0], -l[i][1])
l = sorted(l, key = lambda x: x[0] + x[1])
l.reverse()
#print(l, r)
dp = [[0 for _ in range(r + 1)] for _ in range(q + 1)]
for i in range(q):
	for j in range(r + 1):
		#dp[i][j] = dp[i][j-1]
		if j >= l[i][0] and 0 <= j + l[i][1] <= r:
			dp[i+1][j+l[i][1]] = max(dp[i+1][j+l[i][1]], dp[i][j] + 1)
		dp[i+1][j] = max(dp[i+1][j], dp[i][j])
# for i,x in enumerate(dp):
# 	print(i, *x)
print(max(dp[-1]) + ans)