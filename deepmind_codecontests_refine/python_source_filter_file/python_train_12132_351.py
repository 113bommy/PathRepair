x = int(input())
p = [3, 1, 4, 2, 0, 5]
y = 0
for i in range(6):
    if x & (1 << i):
        y |= 1 << p[i]
print(y)