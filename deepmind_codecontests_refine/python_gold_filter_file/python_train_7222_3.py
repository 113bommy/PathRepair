square = [[0 for i in range(4)] for i in range(4)]
for i in range(4):
    line = input()
    for j in range(4):
        if line[j] == '#':
            square[i][j] = 1
        else:
            square[i][j] = 0

#print(square)
ans = False
for i in range(3):
    for j in range(3):
        s = square[i][j] + square[i][j+1] + square[i+1][j] + square[i+1][j+1]
        if s >= 3 or s <= 1:
            #print(i, j)
            ans = True
            break

    if ans:
        break

if ans:
    print("YES")
else:
    print("NO")
