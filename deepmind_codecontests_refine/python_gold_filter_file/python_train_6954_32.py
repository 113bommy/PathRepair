h,w = map(int,input().split())
s = [input() for _ in range(h)]
cnt = [[-3]*w for _ in range(h)]

for i in range(h):
    c = 1
    for j in range(w):
        if s[i][j] == "#": c = 1
        else:
            cnt[i][j] += c
            c += 1
    c = 1
    for j in range(w)[::-1]:
        if s[i][j] == "#": c = 1
        else:
            cnt[i][j] += c
            c += 1

for j in range(w):
    c = 1
    for i in range(h):
        if s[i][j] == "#": c = 1
        else:
            cnt[i][j] += c
            c += 1
    c = 1
    for i in range(h)[::-1]:
        if s[i][j] == "#": c = 1
        else:
            cnt[i][j] += c
            c += 1

print(max(max(i) for i in cnt))