t = int(input())

while t:
	t-=1
	a, b, n, m = input().split()
	a = int(a); b = int(b); n = int(n); m = int(m)

	if min(a,b) > m and a + b  >= n+m:
		print("YES")
	else:
		print("NO")
