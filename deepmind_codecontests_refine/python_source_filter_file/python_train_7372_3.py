(d, g), *s = [list(map(int, i.split())) for i in open(0)]
s = [[i[0] * -~n * 100 + i[1], i[0]] for n, i in enumerate(s)]
a = 10**3
for b in range(1 << d):
    su = sum(s[i][0] * (b >> i & 1) for i in range(d))
    n = sum(s[i][1] * (b >> i & 1) for i in range(d))
    if su < g:
        m = d-bin(b)[2:].zfill(d).find("0")
        e = -(su-g)//(m*100)
        if e < s[m-1][1]:
            a = min(a,n + e)
    if su >= g:
        a = min(a,n)
print(a)