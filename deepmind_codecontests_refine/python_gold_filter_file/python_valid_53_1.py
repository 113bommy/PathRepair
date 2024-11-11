# cook your dish here
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    ind={}
    x=sorted(a)
    for i in range(n):
        ind[x[i]]=i
    c=1
    for i in range(n-1):
        if ind[a[i]]!=ind[a[i+1]]-1:
            c=c+1
    if c>k:
        print('No')
    else:
        print('Yes')