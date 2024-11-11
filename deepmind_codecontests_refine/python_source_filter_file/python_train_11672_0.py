[n, m, k, l] = map(int, input().split())
if k+l > n:
    print(-1)
else:
    x = (m+k+l)//m
    if x*m <= n:
        print(x)
    else:
        print(-1)