import fractions

[t, w, b] = [int(x) for x in input().split()]
if w > b:
    w, b = b, w
gcd = fractions.gcd(w, b)
m = w * b / gcd
l, k = t // m, t % m
ans = l * w - 1 + min(k + 1, w)
gcd = fractions.gcd(ans, t)
print("%d/%d" % (ans // gcd, t // gcd))