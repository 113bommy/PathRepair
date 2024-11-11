import sys
input = sys.stdin.readline


def main():
    K = input().replace("\n", "")
    D = int(input())
    
    mod = pow(10, 9)+7
    n = len(K)
    dp = [[0]*D for _ in range(n+1)]
    
    dp[0][0] = 1
    sub = 0
    
    if D == 1:
        ans = 0
        for i in range(n):
            ans = (ans*10+int(K[i]))%mod
        print(ans)
        sys.exit()


    for i in range(n):
        if i != 0:
            for j in range(10):
                for k in range(D):
                    dp[i+1][(k+j)%D] += dp[i][k]
                    dp[i+1][(k+j)%D] %= mod
            for j in range(1, 10):
                dp[i+1][j%D] += 1
                dp[i+1][j%D] %= mod
        
        
        for j in range(int(K[i])):
            if i == 0 and j == 0:
                continue
            dp[i+1][(j+sub)%D] += 1
            dp[i+1][(j+sub)%D] %= mod
        sub = (sub+int(K[i]))%D
    
    sub = 0
    for i in range(n):
        sub = (sub+int(K[i]))%D
    if sub == 0:
        dp[n][0] += 1
        dp[n][0] %= mod
        
    
    print(dp[n][0])
    
    
if __name__ == "__main__":
    main()
