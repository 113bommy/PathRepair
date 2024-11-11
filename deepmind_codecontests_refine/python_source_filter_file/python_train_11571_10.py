
n, r = map(int, input().strip().split() )

# r + progression(n - 1 - r)
# r + 2 * a1 + d(n - 1) * n // 2

if r <= n:
	k = r + (2 * 2 + n - r - 2) * (n - r - 1) // 2
else:
	k = n
print (k)
