def f():
    import sys
    input = sys.stdin.readline
    n,q=[int(j) for j in input().split()]
    l=[]
    for i in range(n):
        s,t,x=[int(j) for j in input().split()]
        l.append((s-x,1,x))
        l.append((t-x,0,x))

    for i in range(q):
        d=int(input())
        l.append((d,2,i))

    l.sort()

    ans=[-1]*q
    ll=set()
    m=10**18
    p=False
    for i,j,x in l:
        if j==1:
            ll.add(x)
            if m>x:
                m=x
                p=True
        elif j==0:
            ll.remove(x)
            if x==m:
                p=False
        else:
            if not p:
                if ll:
                    p=True
                    m=min(ll)
                else:
                    m=-1
            ans[x]=m
    print('\n'.join(map(str,ans)))

f()