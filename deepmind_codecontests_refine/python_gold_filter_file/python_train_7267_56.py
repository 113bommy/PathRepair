import sys
from collections import Counter
input = sys.stdin.readline


N = int(input())
memo = [[[-1]*(N+1) for _ in range(N+1)] for _ in range(N+1)]

def dp(a, b, c):
    if a == b == c == 0: return 0
    if memo[a][b][c] != -1:
        return memo[a][b][c]
    
    res = N
    if a > 0: res += a*dp(a-1, b, c)
    if b > 0: res += b*dp(a+1, b-1, c)
    if c > 0: res += c*dp(a, b+1, c-1)
    res /= a+b+c
    
    memo[a][b][c] = res
    return res

def main():
    A = list(map(int, input().split()))
    
    count = Counter(A)
    for i in range(1, 4):
        if not i in count: count[i] = 0
    x, y, z = count[1], count[2], count[3]

    
    ans = dp(x, y, z)
    
    print(ans)
        

    
if __name__ == "__main__":
    main()

