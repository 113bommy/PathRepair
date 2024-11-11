n = int(input())
a = list(map(int, input().split()))
print(n - 1)
for i in range(n - 1):
    j = a.index(min(a[i:]))
    print(i, j)
    a[i], a[j] = a[j], a[i]
 