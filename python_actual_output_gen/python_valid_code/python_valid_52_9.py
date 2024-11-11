t = int(input())
for i in range(t):
    n = int(input())
    mas = [int(s) for s in input().split()]
    k = False
    for i in range(n):
        if mas.count(mas[i]) == 2:
            k = True
            break
    if k:
        print('YES')
    else:
        print('NO')
