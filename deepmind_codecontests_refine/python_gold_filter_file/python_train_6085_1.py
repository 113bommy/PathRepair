import math
a,b=map(int,input().split(' '))
if a==0:
    print(0,' ',1)
    print(0,' ',b)
    print(0,' ',0)
    print(0,' ',b-1)
elif b==0:
    print(1,' ',0)
    print(a,' ',0)
    print(0,' ',0)
    print(a-1,' ',0)
elif a>=b:
    if math.sqrt(a**2+b**2)+a>2*math.sqrt(a**2+(b-1)**2):
        print(0,' ',0)
        print(a,' ',b)
        print(0,' ',b)
        print(a,' ',0)
    else:
        print(0,' ',1)
        print(a,' ',b)
        print(0,' ',0)
        print(a,' ',b-1)
else:
    if math.sqrt(a**2+b**2)+b>2*math.sqrt((a-1)**2+b**2):
        print(0,' ',0)
        print(a,' ',b)
        print(a,' ',0)
        print(0,' ',b)
    else:
        print(1,' ',0)
        print(a,' ',b)
        print(0,' ',0)
        print(a-1,' ',b)
    