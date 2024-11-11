x, y, z, t1, t2,  t3 = [int(x) for x in input().split()]
tangga=abs(x-y)*t1
lift=t2*(abs(x-y)+abs(x-z))+2*t3
if lift<=tangga:
    print('YES')
else:
    print('NO')