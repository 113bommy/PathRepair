def inp():
    return map(int, input().split())


p, q, l, r = inp()
a, c, ans = [], [], 0
for i in range(p + q):
    x, y = inp()
    if i < p:
        a.append([x, y])
    else:
        c.append([x, y])

for i in range(l, r + 1):
    flag = 0
    for j in a:
        for k in c:
            if (k[0] + i >= j[0] and k[0] + i <= j[1]) or (k[1] + i >= j[0] and k[1] + i <= j[1]) or (
                    k[1] + i < j[0] and k[1] + i > j[1]):
                ans += 1
                flag = 1
                break
        if flag:
            break
print(ans)
