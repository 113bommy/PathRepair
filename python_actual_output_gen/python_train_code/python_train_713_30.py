n, m, k = input().split()
n, m, k = int(n), int(m), int(k)

if k <= n-1:
    ans = (k+1, 1)
elif m == 2:
    k -= n
    ans = (n - k, 2)
else:
    k -= n
    row = n - k // (m-1)
    col = k % (m-1)
    if row % 2 == 1:
        col = m - 1 - col
    ans = (row, 2 + col)

print(' '.join(map(str, ans)))
