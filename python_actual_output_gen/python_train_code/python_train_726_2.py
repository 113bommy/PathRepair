s,b = map(int,input().split())
a = [int(s) for s in input().split()]
dg = [[int(s) for s in input().split()] for i in range(b)]
dg.sort()
for i in range(1,b):
    dg[i][1] += dg[i-1][1]
for i in a:
    left = 0
    right = b-1
    if i >= dg[-1][0]:
        print(dg[-1][1])
        continue
    if i < dg[0][0]:
        print(dg[0][1])
        continue
    while True:
        m = (left+right)//2
        if m == left:
            print(dg[m][1], end = ' ')
            break
        if i >= dg[m][0]:
            left = m
        else:
            right = m