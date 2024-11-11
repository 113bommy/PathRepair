import math
t = input()
if len(t)%2 != 0:
    x1 = (len(t)+1)/2
    x2 = (len(t)-1)/2
    y = math.ceil(x2)
    x = math.ceil(x1)
    for i in range(0,x):
         if i == 0:
            print(t[y],end='')
         else:
             print(t[y - i], end='')
             print(t[y+i], end='')

else:
    x1 = len(t)/2
    x = math.ceil(x1)-1
    for i in range(0,len(t)):
        if i %2 == 0:
            print(t[x - i],end='')
            x = x - i
        else:
            print(t[x + i],end='')
            x = x + i
