n, m, k, l = map(int, input().split())

if n < m or l + k > n or ((l + k) // m + int(l+k % m == 0)) * m > n:
    print(-1)
else:
    print((l+k) // m + int(l+k % m == 0))

