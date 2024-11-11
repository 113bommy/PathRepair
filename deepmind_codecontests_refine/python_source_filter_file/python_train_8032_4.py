h, w = map(int, input().split())
v = 0
k = 0
if h >= 3 and w >= 3:
    f = True
    table = []
    for i in range(h):
        a = list(input())
        table.append(a)
        v += a.count("*")
    for i in range(1, h - 1):
        if not f:
            break
        for j in range(1, w - 1):
            if not f:
                break
            if table[i][j] == '*':
                if table[i - 1][j] == table[i + 1][j] == table[i][j + 1] == table[i][j - 1] == '*':
                    k += 1
                    indexi = i - 1
                    while True:
                        if indexi == -1 or table[indexi][j] != '*':
                            break
                        if table[indexi][j] == '*':
                            k += 1
                        indexi -= 1
                    indexi = i + 1
                    while True:
                        if indexi == h or table[indexi][j] != '*':
                            break
                        if table[indexi][j] == '*':
                            k += 1
                        indexi += 1
                    indexj = j - 1
                    while True:
                        if indexj == -1 or table[i][indexj] != '*':
                            break
                        if table[i][indexj] == '*':
                            k += 1
                        indexj -= 1
                    indexj = j + 1
                    while True:
                        if indexj == w or table[i][indexj] != '*':
                            break
                        if table[i][indexj] == '*':
                            k += 1
                        indexj += 1
                    f = False
    if k == v:
        print("YES")
    else:
        print("NO")
                    
else:
    print('NO')