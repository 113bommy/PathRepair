while True:
    try:
        weight = int(input())
    except:
        break
    g = []
    while weight != 1:
        weight, b = divmod(weight, 2)
        g.append(b)
    g.append(weight)
    print(*[pow(2*g[i], i) for i in range(len(g))])