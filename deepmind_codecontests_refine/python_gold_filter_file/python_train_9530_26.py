n = int(input())
a = []
for i in range(n):
    a.append([str(x) for x in input().split()])
    a[i][1], a[i][2] = int(a[i][1]), int(a[i][2])
c = 0 
for i in range(n):
    if(a[i][1] >= 2400 and a[i][2] > a[i][1]):
        print('YES')
        c = 1
        break
if(c == 0):
    print('NO')