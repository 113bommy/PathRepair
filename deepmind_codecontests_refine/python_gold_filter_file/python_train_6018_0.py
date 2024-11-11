M = 10**9 + 7
a = [1] + [0] * 12
p = 1
for c in reversed(input()):
    r = range(10) if c == '?' else (int(c),)
    a = [sum(a[(i - p * j) % 13] for j in r) % M for i in range(13)]
    p = p * 10 % 13
print(a[5])