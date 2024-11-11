t = int(input())

for _ in range(t):
    l ,r, m = map(int, input().split())
    a = 0
    for i in range(l, r+1):
        if(m+l-r <= (((m+r-l)//i)*i) <= m+r-l):
            a = i
            break
    n = (m+r-l)//a
    ans = -m+n*a
    if(ans>=0):
        c = r
        b = c - ans
    else:
        c = l
        b = c - ans
    print(a, b, c)
