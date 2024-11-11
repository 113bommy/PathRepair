h = input().split(' ')
l = list(h)
k = False
n = int(l[0])
d = int(l[1])
m = int(input())
for i in range(m):
    t = input().split(' ')
    l = list(t)
    x = int(l[0])
    y = int(l[1])
    if ((d <= x + y) & (x + y <= 2*n-d) & (d*(-1) <= x - y) & (x-y <= d)):
        print('YES')
    else:
        print('NO')




