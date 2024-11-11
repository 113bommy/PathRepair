n, k = map(int, input().split())
a = [int(x) for x in input().split()]
res = set(a)
if len(res) < k:
    print('NO')
else:
    print('YES')
    print(" ".join([str(a.index(x)+1) for x in res]))

