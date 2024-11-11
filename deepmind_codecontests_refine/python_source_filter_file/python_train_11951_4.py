import sys
input = sys.stdin.buffer.readline

def main():
    N,K = map(int,input().split())
    H = list(map(int,input().split()))
    H = [0]+H
    INF = 10**10
    
    dp = [INF]*(N+1)
    dp[0] = 0
    for i in range(N-K):
        use = [INF]*(N+1)
        for j in range(i,N+1):
            for k in range(j+1,N+1):
                use[k] = min(use[k],dp[j]+max(0,H[k]-H[j]))
        dp = use
    
    print(dp[-1])

if __name__ == "__main__":
    main()
