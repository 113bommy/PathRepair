import math

n = int(input())
a = input()
b = input()
c = 0
D = 5
for i in range(0,n):
    x = math.fabs(int(a[i])-int(b[i]))
    c += x if (x<=D) else (2*D-x)
print(c)
