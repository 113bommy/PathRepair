n, k = map(int, input().split())

if k == 0 or k == n:
    mn = 0

else:
    mn = 1

if 2 * k <= n:
    mx = k

else:
    mx = n - k

print(mn, mx)
