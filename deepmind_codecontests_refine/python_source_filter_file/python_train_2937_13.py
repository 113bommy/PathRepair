r, c = [int(p) for p in input().split()]
if r == 1 and c == 1:
    print(0)
    exit()
elif r == 1:
    print(list(range(1, c+1)))
elif c == 1:
    for i in range(2, r+2):
        print(i)
else:
    matrix = []
    for i in range(2, r+2):
        row = []
        for j in range(1, c+1):
            row.append(i*(r+j))
        matrix.append(row)
    for i in matrix:
        print(*i)