n, k = map(int, input().split())
a = list(map(int, input().split()))
if n==k:
    print(0)
elif k == 1:
    print(a[n-1]-a[0])
else:
    x = []
    for i in range(1, n):
        y = a[i]-a[i-1]
        x.append(y)
    x.sort()
    ans = sum(x[:n-k])
    print(ans)