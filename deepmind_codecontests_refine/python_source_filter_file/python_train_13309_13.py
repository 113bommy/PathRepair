n=int(input())
A=list(map(int,input().split()))
ans=10**9
for t in range(2):
    a=0
    s=0
    for i in range(n):
        a+=A[i]
        if t and a<=0:
            s+=-a+1
            a=1
            t=0
        elif not(t) and a>=0:
            s+=a+1
            a=-1
            t=1
        else:
            t=1-t
    ans=min(s,ans)
print(ans)
