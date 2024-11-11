dice = [1,2,3,4,5,6]
number = list(map(int,input().split()))
direction = str(input())

rotate_n =[2,6,4,3,1,5]
rotate_s =[5,1,3,4,6,2]
rotate_e =[4,2,1,6,5,3]
rotate_w =[3,2,6,1,5,4]

for i in direction:
    result = []
    if i == "N":
        for j in range(6):
            dice[j] = rotate_n[j]
    elif i == "S":
        for j in range(6):
            dice[j] = rotate_s[j]
    elif i == "E":
        for j in range(6):
            dice[j] = rotate_e[j]
    else:
        for j in range(6):
            dice[j] = rotate_w[j]
    for k in dice:
        result.append(number[k-1])
    number = result

print(number[0])