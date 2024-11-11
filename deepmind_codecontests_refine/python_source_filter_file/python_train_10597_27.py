


N,M=map(int, input().split())
key=[]
for i in range(M):
    a,b=map(int, input().split())
    C=list(map(int, input().split()))
    c=0
    for d in C:
        c+=2**(d-1)
    key.append((a,b,c))

dp=[10**8+10]*(2**N)
dp[0]=0
for bi in range(0,2**N):
    for i in range(M):
        t=key[i]
        a,b,c=t
        

        dp[bi|c]=min(dp[bi]+a,dp[bi|c])
if dp[-1]<=10**8+10:
    print(int(dp[-1]))
else:
    print(-1)
    