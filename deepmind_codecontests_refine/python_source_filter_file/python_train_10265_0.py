n, m = map(int,input().split())
a=['']*n
for i in range(n):
    a[n-i-1]=input()
ll, rr, k, l, r = 0, 0, 0, 0, 0
for s in a:
    i, l, r = 1, 0, 0
    for z in s:
        if z=='1':
            if l == 0: l = m - i + 1
            r = i
        i+=1
    if k==0:
        p, q, rr = ll+2*r, ll + m + 1, m + 1
    else:
        p, q = min(ll + 2*r, rr + m+1), min(ll + m+1,rr + 2*l)
    if l or r:
        res=min(ll+r+k,rr+l+k)
    k+=1
    ll, rr = p, q
print(res)
    
