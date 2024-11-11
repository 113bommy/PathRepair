n, k = map(int, input().split())

if n & 1:
    if k > n // 2 + 1:
        k -= n // 2 + 1
        print(2 + 2 * (k - 1))
    else:
        print(1 + 2 * (k - 1))
else:
    if k > n // 2:
        k -= n // 2
        print(2 + 2 * (k - 1))
    else:
        print(1 + 2 * (k - 1))
