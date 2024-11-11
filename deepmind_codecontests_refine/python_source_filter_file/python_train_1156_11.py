from math import log, ceil
d = {}
n = int(input())
if n == 1:
    print('1 0')
    exit(0)
i = 2
while True:
    if i > n:
        break
    if n % i == 0:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
        n //= i
    else:
        i += 1


maxpow = max(d.values())
minpow = min(d.values())
ans = int(ceil(log(maxpow, 2)))
if maxpow & (maxpow - 1) != 0:
    ans += 1
if minpow != maxpow:
    ans += 1
value = 1
for i in d.keys():
    value *= i
print(value, ans)