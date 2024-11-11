n = int(input()) + 1
b, p = 1, []
while b < n + 1:
    d = (2 * b - 1) ** 2 + 8 * (n - b)
    s = int(d ** 0.5)
    s += int((d // s - s) // 2)
    if s * s == d:
        a = s - (2 * b - 1)
        if a % 4 == 0: p.append(b * (a // 2 + 1))
    b *= 2
print('\n'.join(map(str, p)) if p else '-1')