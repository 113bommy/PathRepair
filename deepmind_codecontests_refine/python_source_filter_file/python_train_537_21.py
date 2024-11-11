t=int(input())
for i in range(t):
    n,k,d=map(int,input().split())
    a=list(map(int,input().split()))
    ds=dict()
    s=set()
    ml=1e9
    for i in range(d):
        ds[a[i]]=i
        s.add(a[i])
    ml = min(ml, len(s))
    for i in range(d,n):
        ds[a[i]] = i
        s.add(a[i])
        if ds[a[i-d]]<=(i-d):
            s.discard(a[i])
        ml=min(ml,len(s))
    print(ml)