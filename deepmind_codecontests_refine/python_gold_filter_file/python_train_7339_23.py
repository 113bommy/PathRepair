def board(lst):
    A, B = 1000, 1000
    for i in range(8):
        for j in range(8):
            if lst[j][i] == "B":
                break
            if lst[j][i] == 'W':
                A = min(A, j)
        for j in range(8):
            if lst[7 - j][i] == "W":
                break
            if lst[7 - j][i] == "B":
                B = min(B, j)
    if A <= B:
        return 'A'
    return 'B'


a = [input() for x in range(8)]
print(board(a))
