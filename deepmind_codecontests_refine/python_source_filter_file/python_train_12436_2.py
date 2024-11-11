def computeLPS():
    m = len(pat)
    i, j = 1, 0
    lps = [0 for i in range(m)]
    
    while i < m:
        if pat[i] == pat[j]:
            j += 1
            lps[i] = j
            i += 1
        else:
            if j == 0:
                i += 1
            else:
                j = lps(j - 1)
    return lps


n, w = [int(x) for x in input().split()]
wall = [int(x) for x in input().split()]
ele = [int(x) for x in input().split()]


txt = [wall[i] - wall[i - 1] for i in range(1, n)]
pat = [ele[i] - ele[i - 1] for i in range(1, w)]


lps = computeLPS()

n = len(txt)
m = len(pat)

if m == 0:
    print(n)
else:
    i, j = 0, 0
    ans = 0
    while i < n:
        if pat[j] == txt[i]:
            i += 1
            j += 1
        if j == len(pat):
            ans += 1
            j = lps[j - 1]
        elif i < n and pat[j] != txt[i]:
            if j == 0:
                i += 1
            else:
                j = lps[j - 1]
    print(ans)
