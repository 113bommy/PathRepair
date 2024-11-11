n, k = [int(x) for x in input().split()]
p = [0]*n
for x in range(n):
    p[x] = [x for x in input()]
res = [[0]*n for x in range(n)]
for y in range(n):
    for x in range(n):
        if x + k <= n:
            a = True
            for b in range(k):
                if p[y][x + b] == "#":
                    a = False
            if a:
                for b in range(k):
                    res[y][x+b] += 1
        if y + k <= n:
            a = True
            for b in range(k):
                if p[y + b][x] == "#":
                    a = False
            if a:
                for b in range(k):
                    res[y + b][x] += 1
ans = [1, 1]
m = 0
for y in range(n):
    for x in range(n):
        if res[y][x] > m:
            m = res[y][x]
            ans = [y, x]
print(ans[0] + 1, ans[1] + 1)
