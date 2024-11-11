N, X, Y = map(int, input().split())

and = [0] * (N-1)
for i in range(1,N+1):
	for j in range(i, N+1):
		k = min(j-i, abs(X-i) + abs(Y-j) + 1)
		ans[k-1] += 1

for i in range(N-1):
	print(ans[i])

