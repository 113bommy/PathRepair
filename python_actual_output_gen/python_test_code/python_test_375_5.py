if __name__ == '__main__':
    word = list(input())
    if 'm' in word or 'w' in word:
        print(0)
    elif 'n' not in word and 'u' not in word:
        print(1)
    else:
        n = len(word)
        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 1
        for i in range(2, n + 1):
            if word[i-1] == word[i-2] and (word[i-1] == 'n' or word[i-1] == 'u'):
                dp[i] = (dp[i - 1] + dp[i - 2]) % (10 ** 9 + 7)
            else:
                dp[i] = dp[i-1]
        print(dp[n])
