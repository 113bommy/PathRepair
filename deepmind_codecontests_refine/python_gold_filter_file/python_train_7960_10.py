n    = int(input())
a    = [int(i) for i in input()]
u    = [[] for i in range(10)]
u[2] = [2]
u[3] = [3]
u[4] = [2, 2, 3]
u[5] = [5]
u[6] = [3, 5]
u[7] = [7]
u[8] = [2, 2, 2, 7]
u[9] = [2, 3, 3, 7]
c    = []

for i in a:
    if i > 1:
        c += u[i]
c.sort()
c = list(map(str,reversed(c)))
print(''.join(c))