def scs(str1, str2):
    """Shortest Common Supersequence"""
    INF = 10 ** 9
    dp = [[[INF] * 210 for _ in range(210)] for _ in range(210)]
    dp[0][0][0] = 0
    prv = [[[None] * 210 for _ in range(210)] for _ in range(210)]
    len_str1 = len(str1)
    len_str2 = len(str2)
    
    str1 += "#"
    str2 += "#"
    for i in range(len_str1 + 1):
        for j in range(len_str2 + 1):
            for k in range(201):
                # add "("
                k2 = k + 1
                i2 = i + (str1[i] == "(")
                j2 = j + (str2[j] == "(")
                if dp[i2][j2][k2] > dp[i][j][k] + 1:
                    dp[i2][j2][k2] = dp[i][j][k] + 1
                    prv[i2][j2][k2] = (i, j, k)
            for k in range(201):
                # add ")"
                k2 = k + 1
                i2 = i + (str1[i] == ")")
                j2 = j + (str2[j] == ")")
                if dp[i2][j2][k2] > dp[i][j][k] + 1:
                    dp[i2][j2][k2] = dp[i][j][k] + 1
                    prv[i2][j2][k2] = (i, j, k)
    
    ans = INF
    cnt = 0
    for c, val in enumerate(dp[len_str1][len_str2]):
        if c + val < ans + cnt:
            ans = val
            cnt = c

    res = []
    i, j, k = len_str1, len_str2, cnt

    while i > 0 or j > 0 or k > 0:
        prv_i, prv_j, prv_k = prv[i][j][k]
        if prv_k < k:
            res.append("(")
        else:
            res.append(")")
        i, j, k = prv_i, prv_j, prv_k

    return "(" * (ans - len(res) - cnt) + "".join(res[::-1]) + ")" * cnt

s = input()
t = input()

print(scs(s, t))