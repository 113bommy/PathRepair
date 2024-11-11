a, b = map(int, input().split())
c = []
for i in range(a):
    k = list(map(int, input().split()))
    for j in range(1, len(k)):
        if k[j] not in c:
            c.append(k[j])
if len(c) == b:
    print('YES')
else:
    print('NO')