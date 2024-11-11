n, k = map(int, input().split())
while ((5 * (n - 1) + 10) * n)//2 > 240 - k:
    n -= 1
print(n)