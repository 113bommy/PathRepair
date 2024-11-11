n = int(input())
k = 0
for i in range(n):
    name = [i for i in input().split()]
    if int(name[1]) >= 2400 and int(name[2]) - int(name[1]) > 0:
        k +=1
if k == 0:
    print('NO')
else:
    print('YES') 