import random
n,m = [int(x) for x in input().split()]
z = []
cnt = 0
for i in range(n-1):
    z.append(random.randint(1,9))
x = ''

for i in z:
    x = x+str(i)
if len(z) == 0:
    for i in range(1, 9):
        if int((x + str(i))) % m == 0:
            print(x + str(i))
            cnt = 1
            break
else:
    for i in range(0, 9):
        if int((x + str(i))) % m == 0:
            print(x + str(i))
            cnt = 1
            break
if cnt == 0:
    print('-1')
