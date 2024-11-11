n,k,s=map(int,input().split())
if s==10**9:
    l=[s]*k
    l+=[s+1]*(n-k)
    print(*l)
else:
    l=[s]*k
    l+=[s+1]*(n-k)
    print(*l)
