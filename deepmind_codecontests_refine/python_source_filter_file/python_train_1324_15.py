import math
y,w= list(map(int,input().split()))
a = max(y,w)
if a==1:
    print(1/1)
elif a==2:
    print('5/6')
elif a==3:
    print('2/3')
elif a==4:
    print('1/2')
elif a==5:
    print('1/3')
elif a==6:
    print('1/6')
else:
    print('0/1')