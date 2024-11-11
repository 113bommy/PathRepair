K=int(input())
S=input()
mod=10**9+7
def inv(x):
    return pow(x,mod-2,mod)
N=len(S)
ans=0
tmp1=1
tmp2=1
for i in range(0,K+1):
    ans=ans+(tmp1*tmp2)
    ans%=mod
    tmp1=tmp1*25
    tmp1%=mod
    tmp2=tmp2*(inv(i+1)*(N+K-i))
    tmp2%=mod
    #print(tmp1,tmp2)
print(ans)