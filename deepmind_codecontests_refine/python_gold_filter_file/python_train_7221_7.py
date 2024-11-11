n = 5
x1 = 0
x2 = 0

for i in range(5):
    line = list(map(int, input().split()))
    if 1 in line:
        x1 = i
        x2 = line.index(1)

print(abs(3-x1-1) + abs(3-x2-1))