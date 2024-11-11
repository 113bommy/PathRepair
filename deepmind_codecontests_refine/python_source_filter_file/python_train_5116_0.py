n, h1 = map(int, input().split())
s = list(map(int, input().split()))
l, r = 1, n+1
while r-l > 1:
    h = h1
    m = (l+r)//2
    a = sorted(s[:m])
    for q in range(m-2, -1, -2):
        h -= a[q+1]
    if m % 2 == 1:
        h -= a[0]
    if h < 0:
        r = m
    else:
        l = m
    if r-l == 1:
        print(l)
        break
