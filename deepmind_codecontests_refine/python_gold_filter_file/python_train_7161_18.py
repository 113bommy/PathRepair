n, t = map(int, input().split())
a = [tuple(map(int, input().split())) for _ in range(n)]
a.sort()

d = [0] * (6000)
for c, v in a:
    for i in reversed(range(t)):
        d[i+c] = max(d[i+c], d[i] + v)

print(max(d))