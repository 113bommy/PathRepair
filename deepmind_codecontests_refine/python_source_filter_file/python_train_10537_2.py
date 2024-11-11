for _ in range(int(input())):
    s = list(map(lambda c: ord(c) - 97, input()))
    n = len(s)
    t = list(map(lambda c: ord(c) - 97, input()))
    if len(set(t) - set(s)) > 0:
        print(-1)
        continue
    next_c = [-1]*26
    dp = [[-1]*26 for _ in range(n)]

    for i in range(n-1, -1, -1):
        next_c[s[i]] = i
    for i in range(n-1, -1, -1):
        for j in range(26):
            dp[i][j] = next_c[j]
        next_c[s[i]] = i

    pos = 0
    ans = 1
    for c in t:
        if pos >= dp[pos][c]:
            ans += 1
        pos = dp[pos][c]

    print(ans)
