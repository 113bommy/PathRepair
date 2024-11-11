n, k = map(int, input().split())
if n >= k - 1:
    print((k - 1) // 2)
else:
    t = k - n
    print(max(0, (n - t + 1) // 2))