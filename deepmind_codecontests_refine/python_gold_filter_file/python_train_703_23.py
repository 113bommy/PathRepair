n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(m)]

for x in range(1000):
    ok = True
    s = str(x)
    if len(s) != n:
        continue
    if not all([int(s[a[i][0] - 1]) == a[i][1] for i in range(m)]):
        continue
    print(x)
    exit(0)

print(-1)
