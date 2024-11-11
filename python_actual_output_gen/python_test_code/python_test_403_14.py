n = int(input())
lst = list()
for i in range(n):
    st = list(input().split(' '))
    dis = int(st[1]) - int(st[0])
    a = int(st[2])
    b = int(st[3])
    u = dis / (a + b)
    if dis % (a + b) == 0:
        lst.append(int(a * u))
    else:
        lst.append(-1)

for i in lst:
    print(i)
