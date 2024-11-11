import copy

n = int(input())

dotsa = []
for _ in range(n):
    y,x = map(int,input().split(" "))
    dotsa.append([y,x])

pattern = []
pattern.append(dotsa)


for y in range(8):
    nextpattern = []
    #print("#######")
    #print(pattern)
    for pat in pattern:
        #print(";;;;;;;;;;;;;;;;;;;;;")
        #print(pat)
        flag = False
        for dot in pat:
            if dot[0] == y:
                flag = True
                break

        if flag:
            nextpattern = pattern
            continue

        ifFound = False
        for x in range(8):
            ank = len(pat)
            flag2 = True
            for i in range(ank):
                if abs(pat[i][0]-y) == abs(pat[i][1]-x) or pat[i][1] == x:
                    flag2 = False
                    break
            if flag2:
                #print("appended")
                #print(y)
                #print(x)
                tmp = copy.deepcopy(pat)
                tmp.append([y,x])
                nextpattern.append(tmp)
        #print("x loop end")
    pattern = nextpattern

ans = pattern[0]
board = [["."]*8 for i in range(8)]
#print(ans)
for ele in ans:
    board[ele[1]][ele[0]] = "Q"
for row in board:
    print(''.join(map(str,row)))

