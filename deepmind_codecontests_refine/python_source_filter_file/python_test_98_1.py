test = int(input())
listT = []
for k in range(test): 
    board = input()
    letter = input()
    listT.append((board,letter))
for z in listT:
    boardlen = len(z[0])
    letterlen = len(z[1])
    ans = 0
    if(letterlen > 1):
        location = [j for i in z[1] for j in range(0,boardlen-1) if z[0][j] == i ]
        length = len(location)
        for l in range(0,length-1):
            ans = ans + abs(location[l+1] - location[l])
        print(ans)
    else:
        print(ans)