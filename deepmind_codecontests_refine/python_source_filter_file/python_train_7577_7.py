import sys
M = 10**9 + 7
n = int(input()) * 2
s = list(map(lambda x: int(x == "W"), input()))

lr = [0] * n # L: 0, R: 1

if s[0] or s[-1]:
    print(0)
    sys.exit()

l = 1
ans = 1
for i, v in enumerate(s[1:], 1):
    if v:
        if l % 2:
            l += 1
        else:
            ans *= l
            l -= 1
            lr[i] = 1
    else:
        if l % 2 == 0:
            l += 1
        else:
            ans *= l
            l -= 1
            lr[i] = 1
    if ans > M:
        ans %= M
    if l < 0:
        print(0)
        sys.exit()

if not lr[-1] or l == 0:
    print(0)
    sys.exit()

def fact(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
        if result > M:
            result %= M
    return result
print((ans * fact(n // 2)) % M)
