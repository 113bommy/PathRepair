import copy
n = int(input())
c = []
for z in range(n):
    c.append(list(map(float, input().split())))
ans = 0
for i in range(n):
    x = copy.deepcopy(c)
    x1, y1 = x[i][0], x[i][1]
    r, l, t, b = 0, 0, 0, 0
    for j in range(n):
        if x[j][0] == x1:
            if x[j][1] > y1:
                if t == 0:
                    t += 1
            elif x[j][1] < y1:
                if b == 0:
                    b += 1
        elif x[j][1] == y1:
            if x[j][0] > x1:
                if r == 0:
                    r += 1
            elif x[j][0] < x1:
                if l == 0:
                    l += 1
    if r == 1 and l == 1 and t == 1 and b == 1:
        ans += 1
print(ans)