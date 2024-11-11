(n, m, mi, mx) = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
if a[0]!=mi:
    m += 1
if a[-1]!=mi:
    m += 1
if a[0]<mi:
    m += n+1
if a[-1]>mx:
    m += n+1
print(['Incorrect', 'Correct'][m<=n])