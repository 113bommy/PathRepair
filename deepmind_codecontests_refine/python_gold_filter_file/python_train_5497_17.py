N,K=map(int,input().split())
mod=10**9+7
Layer=[]
a=1
b=1
while(b<=N):
    a=b
    b=N//(N//a)+1
    Layer.append((a,b))
#print(Layer)
num=[x[1]-x[0] for x in Layer]
M=len(Layer)
#print(num)
dp=[[0 for j in range(M+1)] for i in range(K+1)]
dp[0][0]=1
sdp=[0 for i in range(M+2)]
for k in range(K):
    for j in range(M+1):
        sdp[j+1]=(dp[k][j]+sdp[j])%mod
    for j in range(M):
        dp[k+1][j]=(sdp[M-j]*num[j])%mod
ans=0
for j in range(M+1):
    ans+=dp[K][j]
    ans%=mod
print(ans)
