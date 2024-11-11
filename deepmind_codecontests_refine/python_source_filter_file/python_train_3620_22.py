n = int(input())
n1, n2 = 200001, 400001
s1, s2 = [[] for _ in range(n1)], [[] for _ in range(n1)]
s3, s4 = [[] for _ in range(n2)], [[] for _ in range(n2)]
for _ in range(n):
    x, y, u = input().split()
    x, y = int(x), int(y)
    a, b = x + y, x - y + 200000
    s1[x].append([y, u])
    s2[y].append([x, u])
    s3[a].append([b, u])
    s4[b].append([a, u])
ans = 100000000
for t in s1:
    if not t:
        continue
    a, b = -1, -1
    t.sort()
    for tt in t:
        if tt[1] == "U":
            a = tt[0]
        elif tt[1] == "D":
            b = tt[0]
        if not min(a, b) == -1 and a < b:
            ans = min(ans, 5 * (b - a))
for t in s2:
    if not t:
        continue
    a, b = -1, -1
    t.sort()
    for tt in t:
        if tt[1] == "R":
            a = tt[0]
        elif tt[1] == "L":
            b = tt[0]
        if not min(a, b) == -1 and a < b:
            ans = min(ans, 5 * (b - a))
for t in s3:
    if not t:
        continue
    a, b, c, d = -1, -1, -1, -1
    t.sort()
    for tt in t:
        if tt[1] == "U":
            a = tt[0]
        elif tt[1] == "D":
            b = tt[0]
        elif tt[1] == "R":
            c = tt[0]
        elif tt[1] == "L":
            d = tt[0]
        if not min(a, c) == -1 and a > c:
            ans = min(ans, 5 * (a - c))
        if not min(b, d) == -1 and d > b:
            ans = min(ans, 5 * (d - b))
for t in s4:
    if not t:
        continue
    a, b, c, d = -1, -1, -1, -1
    t.sort()
    for tt in t:
        if tt[1] == "U":
            a = tt[0]
        elif tt[1] == "D":
            b = tt[0]
        elif tt[1] == "R":
            c = tt[0]
        elif tt[1] == "L":
            d = tt[0]
        if not min(b, c) == -1 and c < b:
            ans = min(ans, 5 * (c - b))
        if not min(a, d) == -1 and a < d:
            ans = min(ans, 5 * (d - a))
print(ans if not ans == 100000000 else "SAFE")