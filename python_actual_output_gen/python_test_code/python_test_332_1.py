for p in range(0, int(input())):
    n = int(input())
    lista = []
    if n >= 4:
        if n % 2 == 0:
            for i in range(n-1, 0, -2):
                lista.append(i)
        else:
            for i in range(n, 0, -2):
                lista.append(i)
        lista.append(2)
        lista.append(4)
        for i in range(6, n, 2):
            lista.append(i)

    else:
        lista.append(-1)
    print(*lista)
