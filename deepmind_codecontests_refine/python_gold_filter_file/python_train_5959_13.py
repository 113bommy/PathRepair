dimensions = list(map(int, input().split()))
for i in range(dimensions[2]*2):
    temp = input()
result = (dimensions[0] - 1)*'D' + (dimensions[1] - 1)*'R'
for i1 in range(dimensions[1]):
    if i1 % 2 == 0:
        result += (dimensions[0] - 1)*'U'
    else:
        result += (dimensions[0] - 1)*'D'
    if i1 != dimensions[1] - 1:
        result += 'L'
print(len(result))
print(result)
