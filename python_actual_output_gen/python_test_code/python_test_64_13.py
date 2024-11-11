n = int(input())
a = list(map(int, input().split()))
b = [0] * n
ma = a[-1]
for i in range(n - 2, -1, -1):
    if a[i] < ma:
        b[i] = ma - a[i] + 1
    else:
        ma = a[i]
print(*b)
