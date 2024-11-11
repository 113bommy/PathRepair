white = 0
black = 0
for i in range(8):
    line = input()
    for j in line:
        if j == 'Q':
            white += 9
        elif j == 'R':
            white += 5
        elif j == 'B' or j == 'K':
            white += 3
        elif j == 'P':
            white += 1
        elif j == 'q':
            black += 9
        elif j == 'r':
            black += 5
        elif j == 'b' or j == 'k':
            black += 3
        elif j == 'p':
            black += 1
if white > black:
    print('White')
elif white == black:
    print('Draw')
else:
    print('Black')