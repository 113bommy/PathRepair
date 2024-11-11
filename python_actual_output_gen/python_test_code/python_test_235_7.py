a, m = map(int, input().split())
pm = set()
while a % m not in pm:
    pm.add(a % m)
    a += a % m
if 0 in pm:
    print('NO')
else:
    print('YES')