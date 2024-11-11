inp = input().split(' ')
n = int(inp[0])
m = int(inp[1])
array = [int(i) for i in input().split(' ')]
letters = [int(i) for i in input().split(' ')]
index = 0
total = 0
for count,i in enumerate(array):
    total += i
    while letters[index] <= total:
        print(str(count+1) + " " + str(int(letters[index]-total+i)))
        index += 1
        if index >= len(letters):
            break
    if index >= len(letters):
        break

while index < len(letters):
    print(str(count+1) + " " + str(int(letters[index]-total+i)))
    index += 1
