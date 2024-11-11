import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

dig = [119, 18, 93, 91, 58, 107, 111, 82, 127, 123]
pct = [0]*(1<<7)
for bit in range(1<<7):
    for j in range(7):
        if not bit & (1<<j):
            pct[bit|(1<<j)] = pct[bit] + 1

def solve():
    n, k = nm()
    s = [int(input(), 2) for _ in range(n)]
    dp = [[False]*(k+10) for _ in range(n+1)]
    dp[n][k] = True
    for i in range(n-1, -1, -1):
        for j in range(k, 0, -1):
            if dp[i+1][j]:
                for d in range(10):
                    if s[i] & dig[d] == s[i]:
                        dp[i][j - pct[s[i] ^ dig[d]]] = True
    # print(*dp, sep='\n')
    if not dp[0][0]:
        return -1
      
    cur = ''
    ck = 0
    for i in range(n):
        for d in range(9, -1, -1):
            if s[i] & dig[d] == s[i] and dp[i+1][ck + pct[s[i] ^ dig[d]]]:
                ck += pct[s[i] ^ dig[d]]
                cur += str(d)
                break
    return cur

print(solve())
