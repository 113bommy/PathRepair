n, k, t = map(int,input().split())
if t > k or t >= n - k:
    print(k)
elif t <= k:
    print(t)
else:
    print((k + n)-t)

