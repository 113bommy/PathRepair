n = int(input())

c = set()

m = 3
while m < 360:
    if ((m - 2) * 180) % m == 0:
        angle = (m - 2) * 180 // m
        c.add(angle)

    m += 1

for i in range(n):
    a = int(input())

    if a in c:
        print('YES')
    else:
        print('NO')