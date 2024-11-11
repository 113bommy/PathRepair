n = int(input())
a = list(map(abs, map(int, input().split())))
if min(a) > n:
    print(-1)
else:
    m = min(a)
    j = 8
    while a[j] != m:
        j -= 1
    c = n // m
    ans = [str(j + 1)] * c
    n -= c * a[j]
    i = 8
    z = 0
    while i > j and n != 0:
        if a[j] + n >= a[i]:
            while z < len(ans) and a[j] + n >= a[i]:
                n += a[j]
                n -= a[i]
                ans[z] = str(i + 1)
                z += 1
        i -= 1
    print("".join(ans))