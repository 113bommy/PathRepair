N=int(input())
A=list(map(int,input().split()))

XOR=0
for a in A[2:]:
    XOR^=a

S=A[0]+A[1]

DP=[[[1<<60]*2 for i in range(2)] for j in range(60)]
DP[0][0][0]=0

for i in range(59):
    CX=0
    if XOR & (1<<i)!=0:
        CX=1

    CS=0
    if S & (1<<i)!=0:
        CS=1

    CA=0
    if A[1] & (1<<i)!=0:
        CA=1
    
    for j in range(2):
        for k in range(2):
            if DP[i][j][k]==1<<60:
                continue

            for na,nb in [(0,0),(0,1),(1,0),(1,1)]:
                if na^nb != CX:
                    continue
                if (na+nb+j)%2 != CS:
                    continue
                
                if na+nb+j>=2:
                    nj=1
                else:
                    nj=0

                if CA<nb:
                    nk=1
                elif CA==nb:
                    nk=k
                else:
                    nk=0

                DP[i+1][nj][nk]=min(DP[i+1][nj][nk],DP[i][j][k]|((1<<i)*nb))
                #print(i,j,k,nj,nk,DP[i][j][k]|((1<<i)*nb))

ANS=DP[59][0][1]-A[1]

if ANS>=A[0]:
    print(-1)
else:
    print(ANS)


