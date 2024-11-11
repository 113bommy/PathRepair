import sys
for a, b, n in (map(int, l.split()) for l in sys.stdin.readlines()):
    if a >= b:
        a -= b
    a *= 10
    ans = 0
    for _ in [0]*n:
        d, m = divmod(a, b)
        ans += d
        a = m*10
    print(ans)
