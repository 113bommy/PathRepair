n, k = [int(item) for item in input().split()]
a = [int(item) for item in input().split()]

a.sort()

if k == 0:
    if a[0] == 1:
        print(-1)
    else:
        print(1)
elif k == n:
    print(10 ** 9)
else:
    if a[k] == a[k - 1]:
        print(-1)
    else:
        print(a[k - 1])
