import math
n = int(input())
count = 0
for i in range(1, n+1):
    for j in range(i, n+1):
        c = pow(i, 2) + pow(j, 2)
        if (math.sqrt(c) <= n and (math.sqrt(c) == int(math.sqrt(c)))):
            print(i, j, c)
            count += 1
print(count)
# print(math.sqrt(25)==int(math.sqrt(25)))
