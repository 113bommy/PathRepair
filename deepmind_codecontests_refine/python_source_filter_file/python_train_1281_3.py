s = {0: 0, 1: 0}
for i in range(4):
    a, b, c, d = input().split()
    if a == c and b != d: s[0] += 1
    if b == d and a != c: s[1] += 1
    for q in [(a, b), (c, d)]: s[q] = s.get(q, 0) + 1
print('YES' if any(i == 2 for i in s.values()) else 'NO')