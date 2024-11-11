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
dice = list(map(int, input().split()))
D = [dice]
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

x = int(input())
for i in range(x):
    a, b = map(int, input().split())
    for i in range(len(D)):
        if a == D[i][0] and b == D[i][1]:
            print(D[i][2])
            break

