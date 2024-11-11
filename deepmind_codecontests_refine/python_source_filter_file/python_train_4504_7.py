for _ in range(int(input())):
    n, m = (int(i) for i in input().split())
    flag = True
    table = []
    for i in range(n):
        table.append(list(map(int, input().split())))
    for i in range(n):
        for j in range(m):
            if i in {0, n - 1} and j in {0, m - 1} and table[i][j] > 2:
                flag = False
                break
            if i in ({0, n - 1} or j in {0, m - 1}) and table[i][j] > 3:
                flag = False
                break
            if table[i][j] > 4:
                flag = False
                break
    if not flag:
        print("NO")
    else:
        print("YES")
        for i in range(n):
            for j in range(m):
                if i in {0, n - 1} and j in {0, m - 1}:
                    table[i][j] = 2
                elif i in {0, n - 1} or j in {0, m - 1}:
                    table[i][j] = 3
                else:
                    table[i][j] = 4
            print(*table[i])

