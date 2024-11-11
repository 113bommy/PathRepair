s,n = map(int,input().split())
list1 = []
condBool = 1
for k in range(n):
    list_dragon = list(map(int,input().split()))
    list1.append(list_dragon)
list1 = sorted(list1, key=lambda x:x[0])
for x in list1:
    if s < x[0]:
        condBool = 0
        break
    else:
        s += x[1]
if condBool == 0:
    print('NO')
else:
    print('YES')
