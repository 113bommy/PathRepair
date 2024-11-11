n, m = map(int, input().split())
x = [int(i) for i in input().split()]
q = [int(i) for i in input().split()]
p = []
t = []
for i in range(len(q)):
    if q[i] == 0:
        p.append(x[i])
    else:
        t.append(x[i])
ans = [0] * len(t)
i = 0
j = 0
for j in range(len(p)):
    item = p[j]
    if i + 1 < len(t):
        while i + 2 < len(t) and item > t[i + 1]:
            i += 1
        if t[i] <= item <= t[i + 1] or j == 0:
            if abs(item - t[i]) <= abs(item - t[i + 1]):
                ans[i] += 1
            else:
                ans[i + 1] += 1
        else:
            i += 1
    if i == len(t) - 1:
        ans[i] += 1
    j += 1
print(*ans)