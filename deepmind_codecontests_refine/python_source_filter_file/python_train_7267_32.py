from collections import Counter
import sys
input = sys.stdin.buffer.readline

def main():
    n = int(input())
    a = Counter(map(int, input().split()))
    dp = [[[0] * (n+1) for _ in range(n+1)] for _ in range(n+1)]
    for k in range(a[3]+1):
        for j in range(a[2]+a[3]-k+1):
            for i in range(n-j-k+1):
                if i + j + k == 0:
                    continue
                tmp = n
                if i > 0:
                    tmp += i * dp[i-1][j][k]
                if j > 0:
                    tmp += j * dp[i+1][j-1][k]
                if k > 0:
                    tmp += k * dp[i][j+1][k-1]
                dp[i][j][k] = tmp / (i+j+k)
    print(dp[a[1]][a[2]][a[3]])

if __name__ == '__main__':
    main()