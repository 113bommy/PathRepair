characteristic=10**9+7
def plus(input1,input2):
    return (input1+input2)%characteristic
def minus(input1,input2):
    return (input1-input2)%characteristic
def times(input1,input2):
    return (input1*input2)%characteristic
def exponen(input1,input2):
    return pow(input1,input2,characteristic)
def divide(input1,input2):
    return times(input1,exponen(input2,characteristic-2))
N=int(input())
Fact=[1 for i in range(N+1)]
Finv=[1 for i in range(N+1)]
for i in range(1,N+1):
    Fact[i]=times(Fact[i-1],i)
    Finv[i]=divide(1,Fact[i])
ans=0
SGL=[0 for i in range(N)]
for K in range(N):
    if 2*K-N<0:
        continue
    SGL[K]=times(times(Fact[K],Finv[2*K-N]),Fact[K-1])
for K in range(1,N):
    ans=plus(ans,times(SGL[K]-SGL[K-1],K))
print(ans)
