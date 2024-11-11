import sys

dpp = [[0] * 100 for i in range(100)]
used = [[0] * 100 for i in range(100)]
inf = (1 << 300)

def dp(pos, i):
    if pos >= k:
        return '0'
    hh = n ** i
    if pos == k - 1:
        return str(int(s[pos]) * hh)
    if used[pos][i]:
        return dpp[pos][i]
    used[pos][i] = 1
    temp = s[pos]
    ans = inf
    best = '999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999'
    ctr = pos
    while int(temp) < n:
        if (temp[0] == '0' and len(temp) > 1):
            if ctr == k - 1:
                break
            ctr += 1
            temp = s[ctr] + temp
            continue
        tt = dp(ctr + 1, i + 1)
        gg = str(int(tt) + int(temp) * hh)
        if (int(gg) < ans):
            ans = int(gg)
            best = gg
        if ctr == k - 1:
            break
        ctr += 1
        temp = s[ctr] + temp
    dpp[pos] = best
    return best
    

n = int(input())
s = input()[::-1]
k = len(s)
print(int(dp(0, 0)))


