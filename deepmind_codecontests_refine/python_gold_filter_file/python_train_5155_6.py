n = int(input())
a = [int(x) for x in input().split()]*2

ans = min(a) * n

add = 0
l = r = a.index(min(a))

while r < 2*n:
	while r < 2*n and a[r] != a[l]:
		r += 1
	add = max(add, r-l-1)
	l = r
	r += 1

ans += add
print(ans)