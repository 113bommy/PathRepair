n = int(input())
p, s, j = 0, 1, -1
for i, c in enumerate(input()):
    if c in '.?!':
        d = i - j
        if d - 1 > n:
            s = 0
            break
        if p + d > n:
            s += 1
            p = 0
        p += d
        j = i
print(s if s else 'Impossible')