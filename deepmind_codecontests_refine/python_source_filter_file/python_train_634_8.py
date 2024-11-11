def main():
    mod = 1000000007
    s = input()
    l = len(s)
    a = []
    a.append('*')
    for i in range(l):
        if s[i] == 'a':
            a.append(s[i])
        elif s[i] == 'b' and a[-1] != 'b':
            a.append(s[i])
    last = 0
    p = len(a)
    dp = []
    dp.append(0)
    for i in range(p):
        if a[i] == 'a':
            dp.append(dp[i] + last + 1)
        else:
            dp.append(dp[i])
            last = dp[i]
            dp[i + 1] %= mod
    print(dp[-1])


main()