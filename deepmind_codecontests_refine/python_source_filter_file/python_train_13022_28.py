n, m = map(int, input().split())
a = list(range(1,m))
for i in range(n):
    l, r = map(int, input().split())
    for j in range(m):
        if j >= l and j <= r:
            if j in a:
                a.remove(j)
if len(a) > 0:
    print(len(a))
    for i in a:
        print(i, end=' ')
else:
    print(len(a))

