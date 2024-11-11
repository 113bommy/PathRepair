n = int(input())

table = []
for i in range(n):
    table.append(list(map(int, input().split())))
    for j, vl in enumerate(table[i]):
        if vl == 0:
            empty = (i, j)

if n == 1:
    print(1)
else:
    if empty[0] != 0:
        sum_ = sum(table[0])
    else:
        sum_ = sum(table[1])

    table[empty[0]][empty[1]] = sum_ - sum(table[empty[0]])
    if table[empty[0]][empty[1]] == 0:
        print(-1)
    else:
        for row in table:
            if sum_ != sum(row):
                print(-1)
                break
        else:
            for j in range(n):
                s = 0
                for i in range(n):
                    s += table[i][j]
                if sum_ != s:
                    print(-1)
                    break
            else:
                s = 0
                for i in range(n):
                    for j in range(n):
                        if i == j:
                            s += table[i][j]
                if s != sum_:
                    print(-1)
                else:
                    s = 0
                    for i in range(n):
                        for j in range(n):
                            if i == n - 1 - j:
                                s += table[i][j]
                    if s != sum_:
                        print(-1)
                    else:
                        print(table[empty[0]][empty[1]])
