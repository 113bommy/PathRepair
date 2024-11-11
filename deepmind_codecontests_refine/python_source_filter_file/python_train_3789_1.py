n, m = map(int, input().split())
numbers = list(map(int, input().split()))
copy = [0] * n
results = []
accumulator = 0


for i in range(m):
    inputs = input().split()
    if inputs[0] == "3":
        results.append(numbers[int(inputs[1])-1] + accumulator + copy[int(inputs[1])-1])
    elif inputs[0] == "2":
        accumulator += int(inputs[1])
    else:
        copy[int(inputs[1]) - 1] -= accumulator
        numbers[int(inputs[1]) - 1] = int(inputs[2])

print(*results, sep="\n")











