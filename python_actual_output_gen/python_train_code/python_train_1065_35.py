g = {'q':9, 'r':5, 'b':3, 'n':3, 'p':1, 'k':0, '.':0}

matrix = []
for i in range(8):
    matrix.append(input())

white, black = 0, 0
for i in range(8):
    for letter in matrix[i]:
        if(letter.isupper()):
            white += g[letter.lower()]
        else:
            black += g[letter]
if(white == black):
    print("Draw")
if(white > black):
    print("White")
else:
    print("Black")
