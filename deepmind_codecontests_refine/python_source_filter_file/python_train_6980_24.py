house = [[[0]*10 for i in range(3)] for j in range(4)]

n = int(input())
for i in range(n):
    data = list(map(int, input().split()))
    house[data[0]-1][data[1]-1][data[2]-1] = data[3]
    
for i in range(4):
    for j in range(3):
        print('',' '.join(list(map(str,house[i][j]))))
    if i!=3: print('####################')