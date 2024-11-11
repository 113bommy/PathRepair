M = 10**9 + 7
a = [1] + [0] * 12
p = 1
for c in reversed(input()):
    x, y = (0, p * 10) if c == '?' else (int(c), int(c) + 1)
    a = [sum(a[(i - j) % 13] for j in range(x, y, p)) % M for i in range(13)]
    p = p * 10 % 13
print(a[5])
