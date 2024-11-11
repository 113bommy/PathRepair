n, m = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
for i in range(0, n):
	ans += a[i]+1
	if i == n-1:
		ans -= 1

if ans == m:
	print("YES")
else:
	print("NO")