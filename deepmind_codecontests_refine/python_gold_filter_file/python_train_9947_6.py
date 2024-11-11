a = [int(i) for i in input().split()]
t = a[0]
s = a[1]
x = a[2]
if x < t:
    print('NO')
    exit()
if (x - t) % s == 0 or ((x - t) % s == 1 and x - t > 1):
    print('YES')
else:
    print('NO')