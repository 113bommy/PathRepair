import math
a,b=map(int, input().split())
f=a
m=b
while a != 0 and b != 0:
    if a > b:
        a = a % b
    else:
        b = b % a
s=a+b
if abs((f-m)/s)==1:
    print('Equal')
elif a>b:
    print('Masha')
else:
    print('Dasha')