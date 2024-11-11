import sys
rd = sys.stdin.readline

n = int(rd())
a = list(map(int,rd().split()))
pos = 0
sa = [0]*(n-1)
for i in range(n-1):
    sa[i] = a[i+1] - a[i]
    if sa[i] > 0:
        pos += sa[i]
    print((a[0] + pos + 1) // 2)

q = int(rd())
for i in range(q):
    l,r,x = map(int,rd().split())
    if l == 1:
        a[0] += x
    if x > 0:
        if l >= 2:
            if sa[l-2] >= 0:
                pos += x
            else:
                pos += max(0,x+sa[l-2])
            sa[l-2] += x
        if r <= n-1:
            if sa[r-1] >= x:
                pos -= x
            else:
                pos -= max(0,sa[r-1])
            sa[r-1] -= x
    elif x < 0:
        x = -x
        if l >= 2:
            if sa[l-2] >= x:
                pos -= x
            else:
                pos -= max(0,sa[l-2])
            sa[l-2] -= x
        if r <= n-1:
            if sa[r-1] >= 0:
                pos += x
            else:
                pos += max(0,x+sa[r-1])
            sa[r-1] += x
    print((a[0] + pos + 1) // 2)