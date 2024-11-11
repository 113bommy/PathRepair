N,Ma,Mb=list(map(int,input().split()))

mix=set([(0,0)])
ans=10**9
cost={(0,0):0}
for i in range(N):
    a,b,c=list(map(int,input().split()))
    tmp=mix.copy()
    tmp2=cost.copy()
    for x in tmp:
        d=x[0]+a
        e=x[1]+b
        f=min(tmp2.get((d,e),10**9),cost[x]+c)
        cost[(d,e)]=f
        mix.add((d, e))
        if d*Mb==e*Ma and f<ans:
            ans=f
"""
print(cost)
print(mix)
"""
if ans==10**9:
    ans=-1
print(ans)