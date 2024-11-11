F = [[-1, 3, 4], [3, -1, -1], [4, -1, -1]]

n = int(input())
A = tuple(map(int, input().split()))
ans = 0
for i in range(1, n):
	a, b = A[i-1]-1, A[i]-1
	if F[a][b] == -1:
		print('Infinite')
		exit(0)
	ans += F[a][b]
	if a == 0 and i > 1:
		c = A[i-2]-1
		if c == b: continue
		if c == 2: ans -= 2

print('Finite')
print(ans)