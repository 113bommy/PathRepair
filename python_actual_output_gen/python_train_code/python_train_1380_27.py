n, w = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
if (2*a[0] <= a[n - 1]):
    ans = min(3 * n * a[0], w)
else: 
    ans = min(3/2 * n * a[n], w)
print(ans)