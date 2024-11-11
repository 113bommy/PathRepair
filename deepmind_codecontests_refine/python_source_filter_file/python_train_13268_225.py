n = int(input())
sol = 0
for i in range(n):
	pi, qi = map(int, input().split())
	if qi - pi >= n:
		sol += 1
print(sol)