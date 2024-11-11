total = 0

grid = int(input())
l = list()
for i in range(grid):
    a = list(map(int, input().strip().split()))
    l.append(a)
middle = int((grid-1) / 2)

total += l[middle][middle]
l[middle][middle] = 0

for i in range(grid):
    total += l[i][middle]
    total += l[i][i]
    total += l[i][grid-i-1]

total += sum(l[middle])


print(total)