for i in range(4):
    row = list(map(int, input().split(' ')))
    if 1 in row:
        s = abs(2-i) + abs(2 - row.index(1))
        print(s)
        break