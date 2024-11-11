def check(k):
    s = 0
    for i in range(n):
        s+=max(0, a[i] - i//k)
    return s >= m
n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse = True)
low = 1
high = n+1
while low <= high:
    mid = (low+high)//2
    if check(mid):
        high = mid-1
    else:
        low = mid+1
if low <= n:
    print(low)
else:
    print(-1)