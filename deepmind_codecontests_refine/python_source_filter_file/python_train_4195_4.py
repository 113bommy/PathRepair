import sys

# sys.stdin = open('in.txt')

s = sys.stdin.read().split()
p = 0


def getSm(k, a, b, c, d):
    return (k + 1) * a - (k * (k + 1) >> 2) * b * d


t = int(s[p])
p += 1

res = []

for _ in range(t):
    a = int(s[p])
    p += 1
    b = int(s[p])
    p += 1
    c = int(s[p])
    p += 1
    d = int(s[p])
    p += 1
    if a - b * c > 0:
        res.append(-1)
    elif d >= c:
        res.append(a)
    else:
        dn = 0
        up = c + 1
        while up - dn > 1:
            md = (up + dn) >> 1
            if getSm(md, a, b, c, d) < getSm(md + 1, a, b, c, d):
                dn = md
            else:
                up = md
        ans = max(a, getSm(dn, a, b, c, d), getSm(up, a, b, c, d))
        res.append(ans)

print('\n'.join(map(str, res)))
