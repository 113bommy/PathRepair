def solve(s: str) -> int:
    print(s)
    n = len(s)
    dp = [-1] * n

    for idx in range(n - 1, -1, -1):
        if idx * 2 + 1 >= n:
            dp[idx] = 2 if s[idx] == '?' else 1
        else:
            if s[idx] == '?':
                dp[idx] = dp[idx * 2] + dp[idx * 2 + 1]
            elif s[idx] == '0':
                dp[idx] = dp[idx * 2 + 1]
            else:
                dp[idx] = dp[idx * 2]
    return dp
    

input()
s = ' ' + (input()[::-1])
dp = solve(s)
s = [i for i in s]
q = []
for _ in range(int(input())):
    q.append(input().split())
for idx, c in q:
    idx = len(s) - int(idx)
    s[idx] = c
    while idx:
        if idx * 2 + 1 >= len(s):
            if s[idx] == '?':
                dp[idx] = 2
            else:
                dp[idx] = 1
        else:
            if s[idx] == '?':
                dp[idx] = dp[idx * 2] + dp[idx * 2 + 1]
            elif s[idx] == '0':
                dp[idx] = dp[idx * 2 + 1]
            else:
                dp[idx] = dp[idx * 2]
        idx //= 2

    print(dp[1])
