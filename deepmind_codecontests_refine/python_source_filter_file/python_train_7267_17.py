N=int(input())
A=[int(i) for i in input().split()]
I,J,K=0,0,0
for a in A:
    if a==1:
        I+=1
    if a==2:
        J+=1
    if a==3:
        K+=1
L=I+J+K
M=J+K
dp=[[[0]*(K+1) for i in range(M+1)] for i in range(L+1)]
for n in range(1,L+1):#n=i+j+k
    for m in range(min(n,M)+1):#m=j+k
        for k in range(min(m,K)+1):
            j=m-k
            i=n-m
            #print(i,j,k)
            ret=N/(i+j+k)
            if i>0:
                ret+=dp[i-1][j][k]*(i/(i+j+k))
            if j>0:
                ret+=dp[i+1][j-1][k]*(j/(i+j+k))
            if k>0:
                ret+=dp[i][j+1][k-1]*(k/(i+j+k))
            dp[i][j][k]=ret
print(dp[I][J][K])