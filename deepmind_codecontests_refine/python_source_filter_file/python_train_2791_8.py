n,k=map(int,input().split())
h=list(map(int,input().split()))

dp=[0]*n
def calc(n,k,h)
    for i in range(1,n):
        dp[i]=min([dp[j] + abs(h[i]-h[j]) for j in range(max(i-k,0),i)])

calc(n,k,h)
print(dp[-1])
