p = [0,0,0,0]
for i in range(3):
    ai, bi = map(int, input().split())
    p[ai-1] += 1
    p[bi-1] += 1

if 3 in p:
    print('YES')
else:
    print('NO')
