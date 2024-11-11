input = [int(x) for x in input().split(" ")]
i = 0
while input[1] > input[0]:
    input[0] *= 3
    input[1] *= 2
    i += 1
print(i)
    