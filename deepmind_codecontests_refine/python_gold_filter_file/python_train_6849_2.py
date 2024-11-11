h, w, k = map(int, input().split())
s = [list(input()) for _ in range(h)]
g = 1
for i in range(h):
    for j in range(w):
        if s[i][j] != '#':
            continue
        s[i][j] = g
        k = j - 1
        while k >= 0 and s[i][k]=='.':
            s[i][k] = g
            k -= 1
        k = j + 1
        while k < w and s[i][k] == '.':
            s[i][k] = g
            k += 1
        g += 1
for i in range(h - 2)[::-1]:
    if s[i][0]=='.':
        for j in range(w):
            s[i][j] = s[i + 1][j]
for i in range(h):
    if s[i][0] == '.':
        for j in range(w):
            s[i][j] = s[i - 1][j]
for t in s:
    print(*t)
