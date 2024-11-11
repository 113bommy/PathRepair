n,k = map(int,input().split())
v = map(int,input().split())

ans = 0

for l in range(n):
    for r in range(n-l+1):
        if l+r >k:
            break
        nv = v[:l] + v[n-r:]
        nv.sort()
        for i in range(k-l-r):
            if not nv or nv[0] >= 0:
                break
            nv.pop(0)
        ans = max(ans,sum(nv))
print(ans)
