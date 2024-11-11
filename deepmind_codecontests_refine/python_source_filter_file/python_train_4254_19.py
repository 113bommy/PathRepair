n, m = map(int, input().split())
d = {i: 0 for i in range(1, n+1)}
for _ in range(n):
    a, b = map(int, input().split())
    d[a] += 1
    d[b] += 1
for k, v in d.items():
    if v % 2:
        print('NO')
        break
else:
    print('YES')
