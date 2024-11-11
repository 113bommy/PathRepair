p = []
for _ in range(3):
    p += list(map(int, input().split()))
for i in range(4):
    if p.count(i) >= 3:
        print('NO')
        exit(0)
print('YES')
