def main():
    mod=998244353
    n=int(input())
    a=[]
    for i in range(n):
        t=input()
        if t[0]=='-':
            a.append(-1)
        else:
            a.append(int(t.split()[-1]))
    
    ans=0
    for i in range(n):
        if a[i]==-1:
            continue
        dp=[0]*n
        dp[0]=1
        buf=1
        for j in range(n):
            if j<i:
                if a[j]==-1:
                    dp[0]=dp[0]*2%mod
                    for k in range(1,j+1):
                        dp[k-1]=(dp[k-1]+dp[k])%mod
                elif a[j]<=a[i]:
                    for k in range(j-1,-1,-1):
                        dp[k+1]=(dp[k+1]+dp[k])%mod
                else:
                    buf=buf*2%mod
            elif i<j:
                if a[j]==-1:
                    for k in range(1,j+1):
                        dp[k-1]=(dp[k-1]+dp[k])%mod
                elif a[j]<a[i]:
                    for k in range(j-1,-1,-1):
                        dp[k+1]=(dp[k+1]+dp[k])%mod
                else:
                    buf=buf*2%mod
        ans=(ans+a[i]*sum(dp)*buf)%mod
    print(ans)
main()