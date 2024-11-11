n = int(input())
a = list(map(int, input().split()))
a.sort()
if a[2] != a[1]:
    print(a.count(a[2]))
elif a[2] != a[0]:
    c = a.count(a[2])
    print(c * (c - 1) / 2)
else:
    c = a.count(a[2])
    n = 0
    for i in range(c - 2):
        n += (i + 1) * (i + 2) // 2
    print(n)
