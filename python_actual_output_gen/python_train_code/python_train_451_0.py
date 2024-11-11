def search(i):
    l = 0
    r = i - 1
    best = 0
    while l <= r:
        m = (l+r)//2
        if c[m] + c[i] >= 1:
            best = m + 1
            l = m + 1
        else:
            r = m - 1
    return best
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = [a[i] - b[i] for i in range(n)]
c.sort(reverse=True)
ans = 0
print(c)
for i in range(1,n):
    ans += search(i)
print(ans)