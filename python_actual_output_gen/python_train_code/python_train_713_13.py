n, m, k = map(int, input().split())
if (k < n):
    print(1 + k, 1)
else:
    k -= n - 1
    x = k % (m - 1)
    if (k // (m - 1) % 2 == 1):
        x = m - x
    else:
        x += 2
    
    print(n - k // (m - 1) + 1, x)