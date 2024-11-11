t = []
for i in range(10):
    t.append(input())
for i in range(10):
    s = ''
    for j in range(10):
        s = s + t[j][i]
    t.append(s)
for i in range(6):
    s = ''
    for j in range(10 - i):
        s = s + t[i + j][j]
    t.append(s)
for i in range(1, 6):
    s = ''
    for j in range(10 - i):
        s = s + t[j][i + j]
    t.append(s)
for i in range(6):
    s = ''
    for j in range(10 - i):
        s = s + t[i + j][9 - j]
    t.append(s)
for i in range(1, 6):
    s = ''
    for j in range(10 - i):
        s = s + t[j][9 - j - i]
    t.append(s)
for line in t:
    x, o, dot, f = 0, 0, 0, 0
    for i in range(5):
        if line[i] == 'X':
            x += 1
        elif line[i] == 'O':
            o += 1
        elif line[i] == '.':
            dot += 1
        if x == 4 and dot == 1:
            print('YES')
            f = 1
            break
    if f: break
    for i in range(5, len(line)):
        if line[i - 5] == 'X':
            x -= 1
        elif line[i - 5] == 'O':
            o -= 1
        elif line[i - 5] == '.':
            dot -= 1
        if line[i] == 'X':
            x += 1
        elif line[i] == 'O':
            o += 1
        elif line[i] == '.':
            dot += 1
        if x == 4 and dot == 1:
            print('YES')
            f = 1
            break
    if f: break
if not f:
    print('NO')