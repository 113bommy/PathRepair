#

import sys
input=sys.stdin.readline
MOD=10**9+7

fac=[1]*(5*10**5+1)
for i in range(1,5*10**5+1):
    fac[i]=(fac[i-1]*i)%MOD
    
def inv(x):
    return pow(x,MOD-2,MOD)

def nPr(n,r):
    return (fac[n]*inv(fac[n-r]))%MOD
def nCr(n,r):
    return (fac[n]*inv(fac[n-r])*inv(fac[r]))%MOD

def main():
    N,M=map(int,input().split())
    hojo=0
    for i in range(1,N+1):
        hojo+=(-1)**(i)*nCr(N,i)*nPr(M,i)*nPr(M-i,N-i)**2
        hojo%=MOD
    print((nPr(M,N)**2+hojo)%MOD)
    
    
    
if __name__=="__main__":
    main()
