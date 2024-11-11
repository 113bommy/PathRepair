n,m = [int(i)for i in input().split()]
ans = 0
for i in range(n+1):
	b = n - i*i
	if b >= 0 and b * b + i == m: ans += 1
print(ans)	