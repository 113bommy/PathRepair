n,k = map(int, input().split( ))
v = list(map(int, input().split( )))
import bisect
ans = 0
for i in range(k):
    for j in range(min(n-i,k-i)):
        u = v[:j]+v[n-i:]
        u.sort()
        ind = bisect.bisect_left(u,0)
        t = min(ind, k-i-j)
        sm = sum(u[t:])
        if ans <sm:
            #print(i,j,t)
            ans = sm
    
print(ans)