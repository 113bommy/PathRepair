import sys
field = [input() for i in range(4)]

def canWin(f):
    result = False
    #by rows
    for row in f:
        if row.find("xxx") != -1:
            result = True

    #by cols
    transposed_f = ["????" for i in range(4)]
    for i in range(4):
        for j in range(4):
            if transposed_f[i][j] != "?":
                transposed_f[i] = transposed_f[i][:j] + f[j][i] + \
                                  transposed_f[i][j + 1:]
    for row in transposed_f:
        if row.find("xxx") != -1:
            result = True

    #by diagonal(main)
    for i in range(2):
        for j in range(2):
            if f[i][j] == "x" and \
               f[i + 1][j + 1] == "x" and \
               f[i + 2][j + 2] == "x":
                result = True

    #by diagonal(side)
    for i in range(2):
        for j in range(3, 1, -1):
            if f[i][j] == "x" and \
               f[i + 1][j - 1] == "x" and \
               f[i + 2][j - 2] == "x":
                result = True
    
    return result

for i in range(4):
    for j in range(4):
        if field[i][j] == ".":
            field[i] = field[i][:j] + "x" + field[i][j + 1:]
            if canWin(field):
                print("YES")
                sys.exit(0)
            field[i] = field[i][:j] + "." + field[i][j + 1:]

print("NO")