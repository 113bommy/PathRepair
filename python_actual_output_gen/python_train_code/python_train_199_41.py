t = int(input())
for _ in range(t):
    n = int(input())
    res = 0
    mid = n // 2
    for i in range(n - 1, 0, -2):
        res += i * i * mid
        mid -= 1
    print(res)