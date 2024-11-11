# https://codeforces.com/contest/617/problem/C

import math
number_of_flowers,x1,y1,x2,y2 = map(int, input().strip().split(' '))
list_of_flowers, distance_to_r1, distance_to_r2 = [[x1,y1]], [0], []
distance_to_r2.append(int(pow(x2-x1,2)+pow(y2-y1,2)))
for i in range(number_of_flowers):
    input_x1, input_y1 = map(int, input().strip().split(' '))
    list_of_flowers.append([input_x1, input_y1])
    distance_to_r1.append(int(pow(x1-input_x1,2)+pow(y1-input_y1,2)))
    distance_to_r2.append(int(pow(x2-input_x1,2)+pow(y2-input_y1,2)))
result = int(1e9)

for i in range(len(list_of_flowers)):
    max_r2 = 0
    for j in range(len(list_of_flowers)):
        if j != i:
            if distance_to_r1[i] < distance_to_r1[j]:
                max_r2 = max(max_r2, distance_to_r2[j])
    result = min((distance_to_r1[i]+max_r2, result))
print(result)
                
                