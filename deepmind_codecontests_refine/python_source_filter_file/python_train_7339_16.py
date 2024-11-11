Matrix = [[] for x in range(8)]


#file_object= open('TextFile1.txt','r')

for i in range(8):
    #Matrix[i] = [x for x in file_object.readline().rstrip('\n')]
    Matrix[i] = [x for x in input()]

bestWhite = 8
bestBlack = -1

for i in range(8):
    for j in range(8):
        if Matrix[j][i] == 'B':
            break
        elif Matrix[j][i] == 'W':
            if j < bestWhite:
                bestWhite = j
            break
    for k in range(7,-1,-1):
        if Matrix[k][i] == 'W':
            break
        elif Matrix[k][i] == 'B':
            if k > bestBlack:
                bestBlack = k
            break

if 7-bestBlack > bestWhite:
    print('A')
else:
    print('B')