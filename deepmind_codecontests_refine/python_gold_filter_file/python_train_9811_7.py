import bisect

ans=10000000000000000000

def tempCalc(r,b,g):
    return (r-b)**2 +(r-g)**2+(b-g)**2

def getLow(p, x ):
    l = 0
    r = len(p)
    while r-l>1:
        m = (l + r) // 2
        if p[m] <= x:
            l = m
        else:
            r = m
    return p[l]

def getHigh(p,x):
    l = -1
    r = len(p)-1
    while r - l > 1:
        m = (l + r) // 2
        if (p[m] < x):
            l = m
        else:
            r = m
    return p[r]

def solve(a,b,c):
    global ans
    for i in a:
        a1=tempCalc(i,getHigh(b,i),getLow(c, i))
        a2=tempCalc(i,getHigh(c,i),getLow(b, i))
        ans=min(ans,a1,a2)



t = int(input())
for i in range(0,t):
    ans=0xFFFFFFFFFFFFFFFF
    cnt = [int(f) for f in input().split()]

    r=[int(f) for f in input().split()]
    b=[int(f) for f in input().split()]
    g=[int(f) for f in input().split()]

    r.sort()
    b.sort()
    g.sort()

    solve(r,g,b)
    solve(r,b,g)

    solve(g,b,r)
    solve(g,r,b)

    solve(b,g,r)
    solve(b,r,g)

    print(ans)

