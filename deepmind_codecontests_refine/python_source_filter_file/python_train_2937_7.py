def f():
    r, c = [int(s) for s in input().split()]
    if r >= 2 and c >= 2:
        col = list(range(c + 1, r + c + 1))
        col[0] = 1
        for i in col:
            row = [i*j for j in range(2,c+2)]
            print(' '.join(str(s) for s in row))
        return
    if r == 1 and c == 1:
        print(0)
        return
    if r == 1:
        print(' '.join(str(i) for i in range(2,c+2)))
        return
    if c == 1:
        for i in range(2,c+2):
            print(i)

f()