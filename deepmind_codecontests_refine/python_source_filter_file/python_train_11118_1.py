l, r = input().split()
l = int(l)
r = int(r)

dp = [[[-1 for k in range(2)] for j in range(2)] for i in range(64)]

def bbin(num):
    res = []
    while num:
        res.append(num % 2)
        num //= 2

    return res

numr = bbin(r)
numl = bbin(l)
while len(numl) < len(numr):
    numl.append(0)

def rec(pos, brr, brl):
    global numl, numr, dp
    if pos < 0:
        return 1

    if dp[pos][brr][brl] != -1:
        return dp[pos][brr][brl]

    res = 0
    if brr:
        if brl:
            res = 3 * rec(pos - 1, brr, brl)
        else:
            if numl[pos] == 1:
                res = rec(pos - 1, brr, brl)
            else:
                res += (2 * rec(pos - 1, brr, 0))
                res += rec(pos - 1, brr, 1)
    else:
        if numr[pos] == 1:
            if brl:
                res += (2 * rec(pos - 1, 0, brl))
                res += rec(pos - 1, 1, brl)
            else:
                if numl[pos] == 1:
                    res += rec(pos - 1, 0, brl)
                else:
                    res += rec(pos - 1, 0, 0)
                    res += rec(pos - 1, 0, 1)
                    res += rec(pos - 1, 1, 0)
        else:
            if brl:
                res += rec(pos - 1, 0, brl)
            else if numl[pos] == 0:
                res += rec(pos - 1, 0, 0)

    dp[pos][brr][brl] = res % (10**9 + 7)
    return dp[pos][brr][brl]

c = 0
for i in range(len(numl) - 1, -1, -1):
    if numl[i] == 1:
        c += rec(i - 1, 1 if i < len(numl) - 1 else 0, 0)
        break
    else:
        c += rec(i - 1, 1 if i < len(numl) - 1 else 0, 1)

print(c % (10**9 + 7))