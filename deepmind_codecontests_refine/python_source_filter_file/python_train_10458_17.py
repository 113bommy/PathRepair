import math
a = [int(x) for x in input().split()]
a.sort()
combo = 1
t = 0
for i in range(1,len(a)):
    if (a[i] == a[i-1]):
        combo +=1
    else:
        combo == 1
    if (combo == 4):
        t = i
        break;
if (combo != 4):
    print('Alien')
else:
    x = []
    for i in range(len(a)):
        if (math.fabs(t-1.5-i) > 1.5):
            x.append(a[i])
    if x[0] == x[1]:
        print('Elephant')
    else:
        print('Bear')
            
