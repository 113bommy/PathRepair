inp = input().split(' ')
k = int(inp[1])
maxSolved = k
problems = sorted([int(i) for i in input().split(' ')])
other = 0

for i in problems:
    while i > maxSolved*2:
        other += 1
        maxSolved *= 2
    if i > maxSolved and i < maxSolved*2:
        maxSolved = i
print(other)
