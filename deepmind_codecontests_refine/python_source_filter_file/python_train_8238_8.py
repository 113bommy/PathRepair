#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code
from collections import Counter
from math import gcd

if __name__ == "__main__":
    n,x = map(int,input().split())
    a = list(map(int,input().split()))
    
    dp = [ [-1,-1,-1] for i in range(n)]

    dp[0][0] = a[0]
    dp[0][1] = x*a[0]
    dp[0][2] = a[0]
    m = max(dp[0][0],dp[0][1],dp[0][2],0)
    for i in range(1,n):
        dp[i][0] = max(dp[i-1][0]+a[i],a[i])
        dp[i][1] = max(dp[i-1][1] + x*a[i],x*a[i],dp[i-1][0]+x*a[i])
        dp[i][2] = max(dp[i-1][1] + a[i],a[i],dp[i-1][0]+a[i])
        m = max(max(dp[i]),m)
    print(m)