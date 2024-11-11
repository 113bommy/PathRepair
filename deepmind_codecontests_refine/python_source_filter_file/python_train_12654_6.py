N = int(input())

if N == 1:
    temp = int(input())
    print(1)
    exit()

array = [None] * N

for i in range(N):
    array[i] = [int(x) for x in input().split()]
    try:
        column = array[i].index(0)
        row = i
    except ValueError:
        pass

if row == 0:
    magicNumber = sum(array[1])
else:
    magicNumber = sum(array[0])

array[row][column] = magicNumber - sum(array[row])
if array[row][column] < 0:
    print(-1)
    exit()

for i in range(N):
    if sum(array[i]) != magicNumber:
        print(-1)
        exit()

for c in range(N):
    temp = 0
    for r in range(N):
        temp += array[r][c]
    if temp != magicNumber:
        print(-1)
        exit()

temp = 0
for i in range(N):
    temp += array[i][i]
if temp != magicNumber:
    print(-1)
    exit()

temp = 0
for i in range(N):
    temp += array[i][N - i - 1]
if temp != magicNumber:
    print(-1)
    exit()

print(array[row][column])
