N = int(input())
se = [()] * N
for i in range(N):
	x, l = map(int, input().split())
	se[i] = (x-l, x+l)
se = sorted(se, key=lambda x: x[1])
ans = N
for i in range(1, N):
	if se[i-1][1] > se[i][0]:
		se[i][1] = se[i-1][1]
		ans -= 1
print(ans)