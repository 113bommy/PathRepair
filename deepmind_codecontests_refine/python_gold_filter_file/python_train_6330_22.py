N=int(input())
S=[int(input()) for i in range(N)]
mod=998244353
def add(a,b):
    return (a+b)%mod
def sub(a,b):
    return (a-b)%mod
def mul(a,b):
    return ((a%mod)*(b%mod))%mod
def pow(x,y):
    if y==0:
        return 1
    elif y==1:
        return x%mod
    elif y%2==0:
        return pow(x,y//2)**2 % mod
    else:
        return pow(x,y//2)**2 * x % mod
def div(a,b):
    return mul(a,pow(b,mod-2))

sum_S=sum(S)
dp=[[0]*(sum_S+1) for i in range(N)]
dp2=[[0]*(sum_S//2+1) for i in range(N)]

dp[0][0]=2
dp[0][S[0]]=1
dp2[0][0]=1
dp2[0][S[0]]=1
for i in range(1,N):
    for j in range(sum_S+1):
        dp[i][j]=mul(dp[i-1][j],2)
        if j-S[i]>=0 and dp[i-1][j-S[i]]!=0:
            dp[i][j]=add(dp[i][j],dp[i-1][j-S[i]])

        if j<=sum_S//2:
            dp2[i][j]=dp2[i-1][j]
            if j-S[i]>=0 and dp2[i-1][j-S[i]]!=0:
                dp2[i][j]=add(dp2[i][j],dp2[i-1][j-S[i]])

if sum_S%2==0:
    print((pow(3,N)-sum(dp[N-1][sum_S//2:])*3+dp2[N-1][-1]*3)%mod)
else:
    print((pow(3,N)-sum(dp[N-1][sum_S//2+1:])*3)%mod)
