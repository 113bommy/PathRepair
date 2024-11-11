import math
int(input())
a = [int(x) for x in input().split()]
c = 0
for  i in range(len(a)):
    if(a[i] == 1):
        c += 1
if(c > 0):
    print(len(a) - c)
    exit()
x = 10000000
for i in range(len(a)):
    temp = a[i]
    for j in range(i + 1, len(a)):
        temp = math.gcd(a[j], temp)
        if(temp == 1):
            x = min(x, j - i)
if(x == 10000000):
    print('-1')
else:   print(len(a) + x - 1)    