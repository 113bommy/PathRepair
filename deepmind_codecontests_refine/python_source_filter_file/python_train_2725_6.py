from collections import Counter

for _ in range(int(input())):
    n, s = int(input()), input()
    copy = sorted(s)
    dp = Counter()
    pt = 0
    ok = True
    for i in range(n):
        if s[i] == copy[pt]:
            dp[i] = 1
            pt += 1
    for i in range(n):
        if pt >= n:
            break
        if dp[i] == 0 and s[i] == copy[pt]:
            dp[i] = 2
            pt += 1
        elif dp[i] == 0:
            ok = False
            break
    if ok:
        print("".join([str(i) for i in range(1 + max(dp.keys()))]))
    else:
        print('-')