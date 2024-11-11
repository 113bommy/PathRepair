import sys
input = sys.stdin.readline

N,M,K=map(int,input().split())
mod=10**9+7

def Combi2(a,b):#aは大きいが、bは小さいとき
    if b>a:
        return 0
    ANS=1
    for i in range(min(b,a-b)):
        ANS=ANS*(a-i)*pow(min(b,a-b)-i,mod-2,mod)%mod

    return ANS%mod

SUM_N=SUM_M=0
for i in range(N):
    SUM_N+=i*(N-i)

for i in range(M):
    SUM_M+=i*(M-i)

#print((SUM_N*(M**2)+SUM_M*(N**2))/Combi2(N*M,2)*Combi2(N*M,K)*K*(K-1)//2%mod)
print((SUM_N*(M**2)+SUM_M*(N**2))*pow(Combi2(N*M,2),mod-2,mod)*Combi2(N*M,K)*K*(K-1)*pow(2,mod-2,mod)%mod)
