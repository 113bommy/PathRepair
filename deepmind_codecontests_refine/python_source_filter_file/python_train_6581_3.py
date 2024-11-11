MOD = 1000000007
MOD2 = 998244353
ii = lambda: int(input())
si = lambda: input()
dgl = lambda: list(map(int, input()))
f = lambda: map(int, input().split())
il = lambda: list(map(int, input().split()))
ls = lambda: list(input())
for _ in range(ii()):
    n=ii()
    s=si()
    d=dict()
    d['00']=0
    x,y=0,0
    l,r=-1,-1
    mn=100000000000000
    for i in range(1,n+1):
        if s[i-1]=='U':
            y+=1
        elif s[i-1]=='D':
            y-=1
        elif s[i-1]=='L':
            x-=1
        else:
            x+=1
        t=str(x)+str(y)
        if t in d:
            if i-d[t]<mn:
                mn=i-d[t]
                l=d[t]+1
                r=i
        d[t]=i
    if l==-1 and r==-1:
        print(-1)
    else:
        print(l,r)
