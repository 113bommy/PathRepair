colors = input()
instructions = input()

pointer = 0
for index in range(len(instructions)):
    if(instructions[index] == colors[pointer]):
        pointer += 1
print(pointer)
    