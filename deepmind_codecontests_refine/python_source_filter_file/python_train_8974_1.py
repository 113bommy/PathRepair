import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=a[:n][::-1]
    c=a[n:]
    dif_b=[0]*(n+1)
    dif_c=[0]*(n+1)
    min_c={}
    for i in range(1,n+1):
        if b[i-1]==2:
            dif_b[i]=1
        else:
            dif_b[i]=-1
        if c[i-1]==2:
            dif_c[i]=1
        else:
            dif_c[i]=-1
        dif_b[i]+=dif_b[i-1]
        dif_c[i]+=dif_c[i-1]
    for i in range(n+1)[::-1]:
        min_c[dif_c[i]]=i
    dif_init=dif_b[-1]+dif_c[-1]
    ans=10**18
    for i in range(n):
        x=dif_init-dif_b[i]
        if x in min_c:
            ans=min(ans,i+min_c[x])
    print(ans)