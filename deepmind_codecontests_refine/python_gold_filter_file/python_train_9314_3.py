n, x, y = map(int, input().split())
res = set()
for i in range(n):
    a, b = map(int, input().split())
    a -= x ; b -= y
    res.add('-' if a == 0 else b/a)
print(len(res))
