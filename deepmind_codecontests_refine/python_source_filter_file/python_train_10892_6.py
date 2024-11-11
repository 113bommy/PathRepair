#http://codeforces.com/problemset/problem/888/B
#unsolved

x = int(input())
array = input()
position = [0, 0]
output = 0
change = 0

for i in array:
    if i == "U":
        position[1] += 1
    elif i == "D":
        position[1] -= 1
    elif i == "R":
        position[0] += 1
    elif i == "L":
        position[0] -= 1


for j in range(len(array)):
    if array[j] == "L" and position[0] > 0:
            position[0] -= 1
            change += 1

    elif array[j] == "R" and position[0] < 0:
            position[0] += 1
            change += 1

    elif array[j] == "D" and position[1] > 0:
            position[1] -= 1
            change += 1

    elif array[j] == "U" and position[1] < 0:
            position[1] += 1
            change += 1

if position == [0, 0]:
    output = x - change

print(output)