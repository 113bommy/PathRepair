n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
if k == 0:
    if a[0] != 1:
        print(1)
    else:
        print(-1)
elif k == n:
    print(a[n - 1])
else:
    c = 1
    for i in range(1, n):
        if c >= k and a[i - 1] != a[i]:
            break
        c += 1
    if c == k:
        print(a[c - 1])
    else:
        print(-1)
