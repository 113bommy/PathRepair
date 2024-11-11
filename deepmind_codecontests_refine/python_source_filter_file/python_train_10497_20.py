N,K=map(int,input().split())
B=[[0]*(2*K) for i in range(2*K)]
W=[[0]*(2*K) for i in range(2*K)]
w=0
for i in range(N):
    x,y,c=map(str,input().split())
    x=int(x)
    y=int(y)
    if c=="B":
        B[y%(2*K)][x%(2*K)]=+1
    else:
        w+=1
        W[y%(2*K)][x%(2*K)]=+1
sumb=[[0]*(2*K+1) for i in range(2*K+1)]
sumw=[[0]*(2*K+1) for i in range(2*K+1)]
for i in range(2*K):
    for j in range(2*K):
        sumb[i+1][j+1]=sumb[i][j+1]+sumb[i+1][j]-sumb[i][j]+B[i][j]
        sumw[i+1][j+1]=sumw[i][j+1]+sumw[i+1][j]-sumw[i][j]+W[i][j]

ans=0
for i in range(K):
    for j in range(K):
        for _ in range(2):
            s=0
            s+=sumb[i][j]-sumb[i][0]-sumb[0][j]+sumb[0][0]#
            s+=sumb[i+K][j+K]-sumb[i][j+K]-sumb[i+K][j]+sumb[i][j]
            s+=sumb[i][2*K]-sumb[0][2*K]-sumb[i][j+K]+sumb[0][j+K]#
            s+=sumb[2*K][j]-sumb[i+K][j]-sumb[2*K][0]+sumb[i+K][0]#
            s+=sumb[2*K][2*K]-sumb[i+K][2*K]-sumb[2*K][j+K]+sumb[i+K][j+K]#

            s+=sumw[i][j+K]-sumw[0][j+K]-sumw[i][j]+sumw[0][j]#
            s+=sumw[i+K][j]-sumw[i][j]-sumw[i+K][0]+sumw[i][0]#
            s+=sumw[2*K][j+K]-sumw[i+K][j+K]-sumw[2*K][j]+sumw[i+K][j]#
            s+=sumw[i+K][2*K]-sumw[i+K][j+K]-sumw[i][2*K]+sumw[i][j+K]#

            ans=max(ans,s)
            sumb,sumw=sumw,sumb

print(ans)
