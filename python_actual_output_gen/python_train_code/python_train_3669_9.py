n, k, t = map(int, input().split())

if t <= k:
    print(t)
elif t <= n:
    print(n-k)
else:
    re = t - n
    print( n-k-re )

