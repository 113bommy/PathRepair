n, m = list(map(int, input().split()))
c = list(map(int, input().split()))
a = list(map(int, input().split()))
i, j = 0, 0
x = 0
while i < n and j < m:
    if a[j] >= c[i]:
        x += 1
        i += 1
        j += 1
    else:
        i += 1
print(x)