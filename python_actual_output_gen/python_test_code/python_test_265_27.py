n = int(input())
l = [[int(i) for i in input().split()] for i in range(n)]

a = []
b = []
for i in range(n):
    if l[i][0]==1:
        a.append(l[i][1])
    else:
        b.append(l[i][1])

if sum(a)/2*len(a)>=5.0:
    print('LIVE')
else:
    print('DEAD')
if sum(b)/2*len(a)>=5.0:
    print('LIVE')
else:
    print('DEAD')
