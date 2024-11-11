import math
n, v1, v2 = input().split()
n = int(n)
v1 = int(v1)
v2 = int(v2)
t = input().split()
x ,y = input().split()
x = int(x)
y = int(y)
min1 = 1
x1 = int(t[1])
d1 = math.sqrt((x-x1)**2+y**2)
time1 = x / v1 + d1 / v2
for i in range(2, n):
    x1 = int(t[i])
    d = math.sqrt((x-x1)**2+y**2)
    time = x / v1 + d / v2
    if time1 > time :
        time1 = time
        min1 = i
        d1 = d
    elif time == time1 and d < d1 :
        time1 = time
        min1 = i
        d1 =d
print(min1+1)