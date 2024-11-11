def main():
    S = input()
    n = len(S)
    a = {j: i for i, j in enumerate('abcdefghijklmnopqrstuvwxyz')}
    S = [a[i] for i in S]
    dp = [10**9]*(n+1)
    dp[0] = 0

    parity = 0
    dict_parity = {0: 0}

    for i, s in enumerate(S):
        parity ^= 2**s
        ans = i+1
        if parity in dict_parity:
            ans = min(ans, dp[dict_parity[parity]]+1)
        for j in range(26):
            parity2 = parity ^ 2**j
            if parity2 in dict_parity:
                ans = min(ans, dp[dict_parity[parity2]]+1)
        dp[i+1] = ans
        if parity not in dict_parity:
            dict_parity[parity] = ans
        elif dp[dict_parity[parity]] > ans:
            dict_parity[parity] = i+1
    print(dp[-1])


main()
