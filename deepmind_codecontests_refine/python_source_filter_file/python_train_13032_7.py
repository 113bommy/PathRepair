def divisor(d):
    ret = []
    i = 2
    while i*i <= d:
        if d % i == 0:
            ret.append(i)
            while d % i == 0:
                d //= i
        i += 1
    if d > 1:
        ret.append(d)
    return ret


MOD = pow(10, 9) + 7
x, n = map(int, input().split())
ans = 1
for p in divisor(x):
    pw = 0
    fact = p
    while fact <= n:
        pw += n // fact
        fact *= p
    ans = pow(p, pw, MOD)

print(ans)