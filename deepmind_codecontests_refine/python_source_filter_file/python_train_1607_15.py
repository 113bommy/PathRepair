from math import sqrt
coord1 = list(map(int, input().split()))
coord2 = list(map(int, input().split()))

dis = sqrt((coord1[0]-coord2[0])**2 +(coord1[1]-coord2[1])**2 +(coord1[2]-coord2[2])**2) 
if coord1[0] != coord2[0] and coord1[1] != coord2[1] and coord1[2] != coord2[2] and dis <= sqrt(3):
    print("YES")
else:
    print('NO')