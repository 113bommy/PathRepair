r, c = map(int, input().split())
rows, cols = set(), set()
for i in range(r):
    s = input()
    for i, v in enumerate(s):
        if v == 'S':
            rows.add(i)
            cols.add(i)

cake = [[1] * c] * r
count = 0
for i in range(r):
    if i not in rows:
        count += c
        cake[i] = [0] * c
for j in range(c):
    if j not in cols:
        count += sum([cake[i][j] for i in range(r)])

print(count)