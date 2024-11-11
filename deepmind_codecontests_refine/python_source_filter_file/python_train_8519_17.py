n = int(input())
a = list(map(int, input().split()))
ma, mi = max(a), min(a)
if ma - mi > 1:
    print(-1)
elif ma - mi == 1:
    z, o = 0, 0
    for i in range(n):
        if a[i] == ma - 1:
            z += 1
        else:
            o += 1
    if z < ma and ma - z <= o / 2:
        print("Yes")
    else:
        print("No")
else:
    if ma == n - 1 or ma <= n / 2:
        print("Yes")
    else:
        print("No")