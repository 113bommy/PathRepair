h, w, n = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(n)]
l.sort(key=lambda x: (x[1], x[0]))
t = 0
a = [w + 1]
for x, y in l:
    if x > y + t:
        a.append(x)
    elif x == y + t:
        t += 1
print(min(a) - 1)
