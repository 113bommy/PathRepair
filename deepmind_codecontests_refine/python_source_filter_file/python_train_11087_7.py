input()
n, result = [int(x) for x in input().split()], [0]
max = -1

for i in range(len(n) - 2, -1, -1):
    if n[i] < max:
        result.append(max - n[i] + 1)
    else:
        max = n[i]
        result.append(0)

for i in range(len(result) - 1, -1, -1):
    print(result[i], end = ' ')
print()