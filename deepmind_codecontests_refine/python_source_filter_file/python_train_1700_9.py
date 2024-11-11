q = int(input())
for _ in range(q):
    input()
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    t = list(map(int,input().split()))
    ans = [(10**18,1)]*n
    for i in range(k):
        ans[a[i]-1] = (t[i],a[i])
    for i in range(1,n):
        pt = ans[i-1][0]
        pa = ans[i-1][1]
        pv = pt + abs(pa-(i+1))
        ct = ans[i][0]
        ca = ans[i][1]
        cv = ct + abs(ca-(i+1))
        if(pv<cv):
            ans[i] = (pt,pa)
        else:
            ans[i] = (ct,ca)
    for i in range(n-2,-1,-1):
        st = ans[i+1][0]
        sa = ans[i+1][1]
        sv = st + abs(sa-i)
        ct = ans[i][0]
        ca = ans[i][1]
        cv = ct + abs(ca-i)
        if(sv<cv):
            ans[i] = (st,sa)
        else:
            ans[i] = (ct,ca)
    res = []
    for i in range(n):
        res.append(ans[i][0]+abs(ans[i][1]-(i+1)))
    print(*res)

    
