# problem 1305 c
N,mod=map(int,input().split())
a=list(map(int,input().split()))
if N>=mod:
    print(0)
elif N<mod:
    ans=1
    for i in range(N):
        for j in range(i+1,N):
            ans*=abs(a[j]-a[i])
            ans%=mod
    print(ans)
    
