s = input()
sl = len(s)
dp = {}
ct = [0] * sl
for x in range(sl):
    dp[(0, x)] = x - 1 if s[x] == 'L' else x + 1
for i in range(32):
    for j in range(sl):
        dp[(i + 1, j)] = dp[(i, dp[(i, j)])]
for x in range(sl): ct[dp[(32, x)]] += 1
print(' '.join([str(ct[x]) for x in range(sl)]))