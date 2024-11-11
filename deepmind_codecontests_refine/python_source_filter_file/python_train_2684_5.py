#入力部
C= 998244353
N,M,K=map(int,input().split())

#定義部
U=max(N,K)
F=[0]*U
G=[0]*U

F[0]=1
for i in range(1,U):
    F[i]=(F[i-1]*i)%C

G[i]=pow(F[-1],C-2,C)

for j in range(U-2,-1,-1):
    G[j]=(G[j+1]*(j+1))%C

def nCr(n,r):
    if r<0 or n<r:
        return 0
    else:
        return (F[n]*G[r]*G[n-r])

#メイン部
S=0
for k in range(0,K+1):
    S=(S+M*pow(M-1,N-k-1,C)*nCr(N-1,k))%C
    
print(S%C)
