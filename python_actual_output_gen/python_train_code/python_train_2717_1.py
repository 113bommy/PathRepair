r, s = [63], ''.join(input() + 'T' for i in range(8)) + 'T' * 9
for i in range(0, 72, 9):
    t = set()
    for x in r:
        for y in (x - 1, x + 1, x - 9, x + 9, x - 10, x - 8, x + 10, x + 8):
            if s[y] == 'T': continue
            if (y < i or s[y - i] != 'S') and (y < i + 9 or s[y - i - 9] != 'S'): t.add(y)
    r = t
print('WIN' if r else 'LOSE')