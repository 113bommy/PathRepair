import math
N, D = map(int, input().split())
X = []
ans = 0
for i in range(N):
	x = list(map(int, input().split()))
	X.append(x)
	for j in range(i):
		l = 0
		for k in range(D):
			l += (X[j][k] - x[k]) ** 2
		if math.sqrt(l) ** 2 == l:
			ans += 1
print(ans)