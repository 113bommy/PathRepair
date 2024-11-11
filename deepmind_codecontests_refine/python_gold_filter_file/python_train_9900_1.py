n, k = list(map(int, input().split()))
if (k % 2 == 1):
    a1 = k // 2
    a2 = k // 2 + 1
else:
    a1 = k // 2 - 1
    a2 = k // 2 + 1
print(max(0, min(a1, n - a2 + 1)))