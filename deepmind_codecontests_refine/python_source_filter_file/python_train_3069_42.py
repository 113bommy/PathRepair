# A and B and Chess
r1 = input()
r2 = input()
r3 = input()
r4 = input()
r5 = input()
r6 = input()
r7 = input()
r8 = input()

blackCounter = 0

board = (r1, r2, r3, r4, r5, r6, r7, r8)
scores = {'q': 9, 'r': 5, 'b': 3, 'k': 3, 'p': 1,
          'Q': -9, 'R': -5, 'B': -3, 'K': -3, 'P': -1}

for row in board:
    for square in row:
        if square in scores:
            blackCounter += scores[square]


if (blackCounter < 0):
    print('White')
elif(blackCounter > 0):
    print('Black')
else:
    print('Draw')
