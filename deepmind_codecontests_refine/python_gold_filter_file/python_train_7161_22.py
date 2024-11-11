def main():
    n,t=map(int,input().split())
    ab=[list(map(int,input().split())) for _ in [0]*n]
    ab.sort(key=lambda x:x[0])
    dp=[0]*(t+1)
    for a,b in ab:
        for i in range(t-1,-1,-1):
            if a+i>=t:
                dp[t]=max(dp[t],dp[i]+b)
            else:
                dp[i+a]=max(dp[i+a],dp[i]+b)
    print(max(dp))
main()