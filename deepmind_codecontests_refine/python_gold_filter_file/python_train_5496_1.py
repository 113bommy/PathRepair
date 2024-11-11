m = int(input())
ans = -1
all = 0
for i in range(m):
	a,b = map(int, input().split())
	ans += b
	all += a * b

ans += (all-1) // 9
print(ans)
