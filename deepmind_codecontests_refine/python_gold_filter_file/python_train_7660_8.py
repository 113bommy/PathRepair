ind = []
x = 0

n = int(input())
listArray = [int(y) for y in input().split()]

for i in range(n):
    if listArray[i] == 0:
        ind.append(i)

ind.append(900001)
temp = 9000001

for i in range(n):
    if i <= ind[x]:
        print(min((ind[x] - i), abs(i - temp)))
    else:
        temp = ind[x]
        x = x + 1
        if listArray[i] == 0:
            print(0)
        else:
            print(1)

