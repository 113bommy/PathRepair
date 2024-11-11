M = 10**9 + 7
a = [1] + [0] * 12
p = 1
for c in reversed(input()):
    if c > '0':
        r = range(0, p * 10, p) if c == '?' else (p * int(c),)
        a = [sum(a[(i - j) % 13] for j in r) % M for i in range(13)]
    p = p * 10 % 13
print(a[5])
