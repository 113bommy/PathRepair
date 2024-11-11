n, k, t = map(int, input().split())

if t < k:
    print(t)
elif k <= t <= n:
    print(k)
else:
    print(t%k+1)
