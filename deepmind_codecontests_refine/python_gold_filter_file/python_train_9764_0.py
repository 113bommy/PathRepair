N,X=map(int,input().split())
L=sorted(map(int,input().split()),reverse=True)
mod=10**9+7

D=[[0]*(X+1) for i in range(N//2+2)]
D[1][L[0]]=1

for l in L[1:]:
    ND=[[0]*(X+1) for i in range(N//2+1)]

    for c in range(1,N//2+1):
        for s in range(X+1):
            if D[c][s]==0:
                continue
            
            k=D[c][s]

            if s+l+c<=X and c+1<=N//2:
                ND[c+1][s+l]=(ND[c+1][s+l]+k*(c+1))%mod
            ND[c][s]=(ND[c][s]+k*(s-c*(l-1)))%mod

            for i in range(1,min(X-s-c+2,l+1)):
                ND[c][s+i]=(ND[c][s+i]+k*2*c)%mod

            if c==1:
                continue

            for i in range(1,min(X-s-c+3,l+1)):
                ND[c-1][s+i]=(ND[c-1][s+i]+k*(c-1)*(l-i+1))%mod
    D=ND

print(D[1][X])