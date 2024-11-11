N=int(input())
A=list(map(int,input().split()))

mod=10**9+7
ans=0

for i in range(60):
    a=0
    for x in A:
        if x>>i&1:
            a+=1
    ans+=a*(N-a)*pow(2,i,mod)
    ans%=mod

    
print(ans)
