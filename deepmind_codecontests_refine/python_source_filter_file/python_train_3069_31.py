board = [input() for _ in range(8)]
weight = {'q': 9, 'r': 5, 'b': 3, 'k': 3, 'p': 1}
white, black = 0, 0
for i in board:
    for j in i:
        if j in weight:
            black += weight[j]
        elif j.lower() in weight:
            white += weight[j.lower()]
if white > black:
    print('White')
elif white < black:
    print('Black')
else:
    print('Draw')