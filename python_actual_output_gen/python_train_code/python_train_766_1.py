q = int(input())
for _ in range(q):
    n, m = map(int, input().split())
    data = []
    nn, mm = [0] * n, [0] * m
    for j in range(n):
        data.append(input())
        for k in range(m):
            if data[-1][k] == "*":
                nn[j] += 1
                mm[k] += 1
    nnn = max(nn)
    mmm = max(mm)
    fl = 0
    for i in range(n):
        if fl == 1:
            break
        else:
            for j in range(m):
                if nn[i] == nnn and mm[j] == mmm:
                    if data[i][j] == ".":
                        print(n - nnn + m - mmm - 1)
                        fl = 1
                        break
    else:
        print(n - nnn + m - mmm)

    
            