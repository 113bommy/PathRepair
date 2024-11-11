# coding: utf-8
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
colors = [str(i) for i in range(1,k+1)]
minnum = min(a)
if minnum>0:
    a = [i+1-minnum for i in a]
if max(a)>k:
    print('NO')
elif minnum>0:
    print('YES')
    for i in range(n):
        print(' '.join([colors[0] for j in range(minnum-1)] + colors[0:a[i]]))
else:
    print('YES')
    for i in range(n):
        print(' '.join(colors[:a[i]]))
