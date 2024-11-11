x = int(input())
z = -1
i = 0
y = []
while z + i + 1 <= x:
    if z == -1:
        z = 0
    i += 1
    z += i
    y.append(i)
print(i)
y[i-1] += x-z
for i in y:
    print(i, end=' ')
