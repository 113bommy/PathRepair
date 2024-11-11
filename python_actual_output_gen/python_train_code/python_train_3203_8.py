n, k = map(int, input().split())
a = list(map(int, input().split()))
c = 0
a.sort()
for i in range(n - 1):
    for j in range(i + 1, n):
        if a[j] - a[i] <= k:
            c += 1
print(c)