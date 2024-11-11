import math

l = [int(x) for x in input().split()]

n , m = l

table = []

for i in range(n):
    if(i % 2 == 0):
        table.append(['#'] * m)
        table[i] = "".join(table[i])

    elif((math.floor(i / 2)) % 2 == 0):
        table.append((['*'] * (m - 1)) + ["#"])
        table[i] = "".join(table[i])

    else:
        table.append(["#"] + (["*"] * (m - 1)))
        table[i] = "".join(table[i])


for i in range(n):
    print(table[i])
