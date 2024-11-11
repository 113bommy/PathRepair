def main(n, s):
    a = 0
    b = 0
    c = 0
    d = 0

    for i in range(n):
        if s[i] == 'r' and i % 2 == 0:
            a += 1
        if s[i] == 'b' and i % 2 == 1:
            b += 1
        if s[i] == 'b' and i % 2 == 0:
            c += 1
        if s[i] == 'r' and i % 2 == 1:
            d += 1
    return min(max(a, b), max(c, d))

print(main(int(input()), list(input())))
