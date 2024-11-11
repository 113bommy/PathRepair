import bisect
import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
M = 998244353

def main(t):


    n = int(input())
    dp = [0]*(n+1)
    accudp = [0]*(n+1)


    state = [0]*n


    trans = []
    for i in range(n):
        y,x,f = map(int,input().split())
        state[i] = f
        trans.append(y)
        loc = bisect.bisect(trans,x)
        
        dp[i+1] = accudp[i] - accudp[loc] + y - x
        dp[i+1] = dp[i+1]%M 

        accudp[i+1] = accudp[i] + dp[i+1]
        accudp[i+1] = accudp[i+1]%M

    ans = (trans[-1]+1)%M

    for i in range(n):
        if state[i]==1: 
            ans += dp[i+1]
            ans = ans%M    

        








    print(ans)




















T = 1 #int(input())
t = 1
while t<=T:
    main(t)
    t += 1
