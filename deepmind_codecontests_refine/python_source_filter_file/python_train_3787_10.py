input_list = []
num = 0
while True:
    if num == 2:
        break
    elif num == 1:
        line = list(input())
    else:
        line = input()
        line = line.split()
        line = list(map(int, line))
    input_list.append(line)
    num += 1

# input_list.__delitem__(0)
queue = input_list[1]
for sec in range(input_list[0][1]):
    count = 0
    while count < input_list[0][0]:
        if queue[count] == "B" and count != input_list[0][0] - 1 and queue[count + 1] == "G":
            queue[count] = "G"
            queue[count + 1] = "B"
            count += 1
        count += 1

print(queue)
