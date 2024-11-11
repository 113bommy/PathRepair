def north(list):
    List = []
    List.append(list[1])
    List.append(list[5])
    List.append(list[2])
    List.append(list[3])
    List.append(list[0])
    List.append(list[4])
    return List

def west(list):
    List = []
    List.append(list[2])
    List.append(list[1])
    List.append(list[5])
    List.append(list[0])
    List.append(list[4])
    List.append(list[3])
    return List
    
def south(list):
    List = []
    List.append(list[4])
    List.append(list[0])
    List.append(list[2])
    List.append(list[3])
    List.append(list[5])
    List.append(list[1])
    return List

def east(list):
    List = []
    List.append(list[3])
    List.append(list[1])
    List.append(list[0])
    List.append(list[5])
    List.append(list[4])
    List.append(list[2])
    return List

def sort123(DD):
    D = [DD]
    for i in range(0, 3):
        D.append(north(D[i]))
        D.append(south(west(D[0])))
        D.append(south(east(D[0])))
    for i in range(6):
        for j in range(3):
            if j == 0:
                D.append(east(D[i + j]))
            else:
                D.append(east(D[5 + 3 * i + j]))
    D.sort()
    return D[0]

n = int(input())
dice = []
for i in range(n):
    dice.append(sort123(list(map(int, input().split()))))
key = 0
for i in range(1, len(dice)):
    if key == 1: break
    for j in range(i + 1, len(dice)):
        if dice[i] == dice[j]:
            print('No')
            key = 1
            break
if key == 0:
    print('Yes')
