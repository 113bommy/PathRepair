n = int(input())
b = [int(i) for i in input().split()]
cont = 1110000
if n < 3:
    print("-1")
else:
    for d1 in range(-1, 2):
        for d2 in range(-1, 2):
            a = []
            a += [b[0] + d1]
            a += [b[1] + d2]
            c = abs(d1) + abs(d2)
            f = 1
            for i in range(2, n):
                a += [a[0] + i * (a[1] - a[0])]
                if abs(a[i] - b[i]) > 1:
                    f = 0
                    break
                elif a[i] != b[i]:
                    c += 1
            if f == 1:
                cont = min(cont, c)
    if cont == 1110000:
        cont = -1
    print(cont)